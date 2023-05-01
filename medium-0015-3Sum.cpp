class Solution {
public:
    std::vector<std::vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        std::set<vector<int>> triplets;

        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    triplets.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                } else if (nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                }            
            }
        }

        std::vector<vector<int>> result(triplets.begin(), triplets.end());
        return result;
    }
};