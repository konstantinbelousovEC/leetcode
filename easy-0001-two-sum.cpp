// Array Hash Table

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> nums_map;
        
        int i = 0;
        while (i < nums.size()) {
            int x = target - nums[i];
            if (nums_map.count(x)) return {nums_map[x], i};
            nums_map[nums[i]] = i;
            i++;
        }

        return {};
    }
};
