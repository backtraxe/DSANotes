#include <cassert>
#include <vector>

using namespace std;

class MergeSort {
public:
    static void mergeSort(vector<int>& nums) noexcept {
        mergeSort(nums, 0, nums.size());
    }

    static void mergeSort(vector<int>& nums, int left, int right) noexcept {
        // [left, right)
        if (left + 1 >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid, right);

        // 2路归并
        vector<int> tmp(right - left);
        int i = left;
        int j = mid;
        int k = 0;

        while (i < mid && j < right) tmp[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
        while (i < mid) tmp[k++] = nums[i++];
        while (j < right) tmp[k++] = nums[j++];

        // 复制覆盖原值
        for (int i = left; i < right; i++) nums[i] = tmp[i - left];
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