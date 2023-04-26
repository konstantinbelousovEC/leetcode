#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> hash_table;
        for (int i = 0; i < nums.size(); i++) {
            hash_table.insert({nums[i], i});
        }
        for (int i = 0; i < nums.size(); i++) {
            int difference = target - nums[i];
            if (hash_table.count(difference) > 0 && hash_table[difference] != i) {
                vector res{i, hash_table[difference]};
                return res;
            }
        }
        return {};
    }
};

void Tests() {
    Solution solution;
    {
        vector v{2,7,11,15};
        vector expected{0,1};
        assert(solution.twoSum(v, 9) == expected);
    }
    {
        vector v{3,2,4};
        vector expected{1,2};
        assert(solution.twoSum(v, 6) == expected);
    }
    {
        vector v{3,3};
        vector expected{1,0};
        assert(solution.twoSum(v, 6) == expected);
    }

    cout << "Tests passed"s << endl; 
}

int main() {

    Tests();

    return 0;
}