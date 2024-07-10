#include <cassert>
#include <utility>
#include <vector>

using namespace std;

class HeapSort {
public:
    static void heapSort(vector<int>& nums) noexcept {
        int n = nums.size();
        // 最大堆建堆，从最后一个叶节点开始
        for (int i = n / 2; i >= 0; i--) downFloat(nums, i, n);
        // 依次将堆顶元素与最后一个元素交换
        for (int i = 1; i < n; i++) {
            swap(nums[0], nums[n - i]);
            downFloat(nums, 0, n - i);
        }
    }

    static void downFloat(vector<int>& nums, int i, int size) noexcept {
        // 下沉，size 表示当前堆中节点数量
        while (i * 2 + 1 < size) {
            // 从两个子节点中选择值更大的节点
            int j = i * 2 + 1;
            if (j + 1 < size && nums[j] < nums[j + 1]) ++j;
            // 不满足最大堆则交换调整
            if (nums[i] < nums[j]) swap(nums[i], nums[j]);
            i = j;
        }
    }
};

bool checkSorted(vector<int>& nums, bool ascend = true) {
    for (size_t i = 1; i < nums.size(); i++) {
        if (ascend && nums[i - 1] > nums[i]) return false;
        if (!ascend && nums[i - 1] < nums[i]) return false;
    }
    return true;
}

int main() {
    vector<int> nums = {3, 1, 2, 5, 4};
    HeapSort::heapSort(nums);
    assert(checkSorted(nums));
    return 0;
}