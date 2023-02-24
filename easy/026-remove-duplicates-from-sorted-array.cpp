#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[k] != nums[i] && ++k != i) {
                nums[k] = std::move(nums[i]);
            }
        }
        return ++k;
    }
};

void Test() {
    Solution solution;

    {
        vector v{1,2,2,3,4,5,5,};
        vector exp{1,2,3,4,5};
        int k = solution.removeDuplicates(v);
        assert(k == 5);
        equal(exp.begin(), exp.end(), v.begin());
    }
    {
        vector v{1,1};
        vector exp{1};
        int k = solution.removeDuplicates(v);
        assert(k == 1);
        equal(exp.begin(), exp.end(), v.begin());
    }

    cout << "Tests passed"s << endl;
}

int main() {
    Test();
    return 0;
}