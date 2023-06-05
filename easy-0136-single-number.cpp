class Solution {
public:
    inline int singleNumber(vector<int>& nums) {
        int single = 0;
        std::for_each(nums.begin(), nums.end(), [&single](int elem){
            single = single ^ elem;
        });
        return single;
    }
};