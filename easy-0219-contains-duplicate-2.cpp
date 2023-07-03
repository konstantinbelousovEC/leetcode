class Solution {
public:
    inline bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_map<int,int> hash_table;
        
        for(int i = 0; i < nums.size(); i++) {
            if(hash_table.count(nums[i])) {
                if( abs(i - hash_table[nums[i]]) <= k ) return true;
            }

            hash_table[nums[i]] = i;
        }

        return false;
    }
};