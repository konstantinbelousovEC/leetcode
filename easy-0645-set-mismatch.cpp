class Solution {
public:
    std::vector<int> findErrorNums(std::vector<int>& nums) const {
        int dup = -1, miss = 1;

        for (auto n : nums) {
            if (nums[std::abs(n) - 1] < 0) {
                dup = std::abs(n);
            } else {
                nums[std::abs(n) - 1] *= -1;
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) miss = i + 1;
        }

        return {dup, miss};
    }
};