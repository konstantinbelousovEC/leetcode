class Solution {
public:
    constexpr static int K = 10000;
    
    // N + K
    inline int arrayPairSum(vector<int>& nums) {
        //std::vector<int> element_to_count(2 * K + 1, 0);
        int element_to_count[2 * K + 1] = {0};
        for (int element : nums) {
            element_to_count[element + K]++;
        }
        
        int max_sum = 0;
        bool is_even_index = true;
        for (int element = 0; element <= 2 * K; element++) {
            while (element_to_count[element]) {
                max_sum += (is_even_index ? element - K : 0);
                is_even_index = !is_even_index;
                element_to_count[element]--;
            }
        }
        return max_sum;
    }

    // NlogN
    inline int arrayPairSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size() - 1; i += 2) {
            res += nums[i];
        }

        return res;
    }
};