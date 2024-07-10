#include <cassert>
#include <vector>

using namespace std;

class MergeSort {
public:
    static void mergeSort(vector<int>& nums) noexcept {
        mergeSort(nums, 0, nums.size());
    }

    static void mergeSort(vector<int>& nums, int left, int right) noexcept {
        int n = nums.size();
        vector<int> tmp(n);
        // 自底向上，span 从 2 到 n
        for (int span = 2; span / 2 < n; span *= 2) {
            for (int left = 0; left < n; left += span) {
                // [l, m) 和 [m, r) 已有序
                int l = left;
                int m = min(l + span / 2, n);
                int r = min(left + span, n);

                // 最后一个 span 实际长度不到一半，无需合并
                if (m == n) break;

                // 2路归并
                int i = l;
                int j = m;
                int k = 0;
                while (i < m && j < r) tmp[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
                while (i < m) tmp[k++] = nums[i++];
                while (j < r) tmp[k++] = nums[j++];
                // 复制覆盖原数组
                for (int i = l; i < r; i++) nums[i] = tmp[i - l];
            }
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
    MergeSort::mergeSort(nums);
    assert(checkSorted(nums));
    return 0;
}