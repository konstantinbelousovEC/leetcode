class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        
        int closest_result = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int current = nums[i] + nums[j] + nums[k];

                if (current == target) {
                    return target;
                } else if (current > target) {
                    if (current - target < std::abs(target - closest_result)) {
                        closest_result = current;
                    }
                    k--;
                } else {
                    if (target - current < std::abs(target - closest_result)) {
                        closest_result = current;
                    }
                    j++;
                }
            }
        }

        return closest_result;
    }
};