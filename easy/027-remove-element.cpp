#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size() - 1;
        for (int i = 0; i <= k; i++) {
            if (nums[i] == val) {
                nums[i] = nums[k];
                k--;
                i--;
            }
        }
        return ++k;
    }
};

void Test() {
	Solution solution;

	{
		vector v{1,2,3,4,10,3,4,5,7};
		const int val_to_remove = 10;
		vector exp{1,2,3,4,3,4,5,7};
		int k = solution.removeElement(v, val_to_remove);
		assert(k == 8);
	}
	{
		vector v{1,2,2,4,2,3,2,5,2};
		const int val_to_remove = 2;
		vector exp{1,4,3,5};
		int k = solution.removeElement(v, val_to_remove);
		assert(k == 4);
	}

	cout << "Tests passed"s << endl;
}

int main() {
	Test();
	return 0;
}