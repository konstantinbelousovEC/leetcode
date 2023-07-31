class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) const noexcept {
        std::vector<int> res{-1, -1};

        if (nums.empty()) return res;

        auto lower = std::lower_bound(nums.begin(), nums.end(), target);
        if (lower == nums.end() || *lower > target) return res;
        res[0] = lower - nums.begin();

        auto upper = std::lower_bound(nums.begin(), nums.end(), target + 1);

        if (upper != nums.end()) res[1] = upper - 1 - nums.begin();
        else res[1] = nums.size() - 1;
        

        return res;
    }
};