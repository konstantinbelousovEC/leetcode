class Solution {
public:
    int findMin(const std::vector<int>& nums) const noexcept {
        int i = 0, j = nums.size() - 1;

        int min;
        while (i < j) {
            if (nums[i] <= nums[j]) return nums[i];

            int k = i + (j - i) / 2;

            if (nums[k] < nums[i]) j = k;
            else if (nums[j] < nums[k]) i = k + 1;
        }

        return nums[i];
    }
};
