#include <cassert>
#include <vector>

using namespace std;

class QuickSort {
public:
    static void quickSort(vector<int>& nums) noexcept {
        quickSort(nums, 0, nums.size());
    }

    static void quickSort(vector<int>& nums, int left, int right) noexcept {
        // [left, right)
        if (left >= right) return;

        // 随机选择一个元素
        int pivotIdx = getPivotIndex(nums, left, right);
        int pivot = nums[pivotIdx];
        swap(nums[left], nums[pivotIdx]);

        // 二分
        int l = left;
        int r = right - 1;

        while (l < r) {
            while (l < r && nums[r] >= pivot) --r;
            nums[l] = nums[r];
            while (l < r && nums[l] <= pivot) ++l;
            nums[r] = nums[l];
        }
        // 归位，每次排序归位一个元素
        nums[l] = pivot;

        quickSort(nums, left, l);
        quickSort(nums, l + 1, right);
    }

    static int getPivotIndex(vector<int>& nums, int left, int right) noexcept {
        // 1.取左端/居中/右端元素。
        // 2.取左端、居中、右端元素中的中间值。（推荐）
        // 3.取随机值。
        int l = left;
        int r = right;
        int m = l + (r - l) / 2;

        if ((nums[l] <= nums[m] && nums[m] <= nums[r]) || (nums[r] <= nums[m] && nums[m] <= nums[l])) {
            return m;
        } else if ((nums[l] <= nums[r] && nums[r] <= nums[m]) || (nums[m] <= nums[r] && nums[r] <= nums[l])) {
            return r;
        } else {
            return l;
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
    QuickSort::quickSort(nums);
    assert(checkSorted(nums));
    return 0;
}