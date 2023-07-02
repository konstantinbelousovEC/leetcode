auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    inline bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_map<int, int> hash_table;
        hash_table.reserve(nums.size());

        auto iterator = std::find_if(nums.begin(), nums.end(), [&hash_table](int elem) {
            hash_table[elem]++;
            return hash_table[elem] > 1;
        });

        return iterator != nums.end();
    }
};