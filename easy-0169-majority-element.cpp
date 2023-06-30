class Solution {
public:
    inline int majorityElement2(std::vector<int>& nums) {
        std::unordered_map<int, int> table;
        for (int elem : nums) {
            table[elem] += 1;
        }


        int elem = nums.front();
        int max = 0;
        for (auto [key, value] : table) {
            if (value > max) {
                max = value;
                elem = key;
            }
        }

        return elem;
    }

    inline int majorityElement(std::vector<int>& nums) {
        int element = nums.front();
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) element = nums[i];
            count += (element == nums[i]) ? 1 : -1;
            if (count > (nums.size() / 2)) break;
        }
        return element;
    }
};