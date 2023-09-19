class Solution {
public:
    int search(const vector<int>& nums, int target) const noexcept {
        int i = 0, j = nums.size() - 1;

        while (i <= j) {
            int k = i + (j - i) / 2;
            
            if (nums[k] == target) return k;

            if (nums[i] <= nums[k]) {
                if (nums[i] <= target && target < nums[k]) j = k - 1;
                else i = k + 1;
            } else {
                if (nums[k] < target && target <= nums[j]) i = k + 1;
                else j = k - 1;
            }
        }

        return -1;
    }
};
