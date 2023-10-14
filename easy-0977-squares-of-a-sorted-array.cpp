// Array | Two pointers | Sorting

class Solution {
public:
    std::vector<int> sortedSquares(const std::vector<int>& nums) const {
        int i = 0, j = nums.size() - 1, k = j;
        std::vector<int> res(j + 1, 0);

        while (k >= 0) {
            if (std::abs(nums[i]) > std::abs(nums[j])) {
                res[k] = std::pow(nums[i], 2);
                i++;
            } else {
                res[k] = std::pow(nums[j], 2);
                j--;
            }
            k--;
        }

        return res;
    }
};

