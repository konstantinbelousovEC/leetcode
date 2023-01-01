#include <iostream>
#include <cassert>

class Solution {
public:
	bool IsPolindrome(int x) {
		if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        return x == revertedNumber || x == revertedNumber/10;
	}
};

int main() {
	Solution s;

	assert(s.IsPolindrome(121));
	assert(!s.IsPolindrome(-121));
	assert(s.IsPolindrome(12121));
	assert(!s.IsPolindrome(120));
	assert(s.IsPolindrome(1));
	assert(!s.IsPolindrome(111110));
	assert(s.IsPolindrome(101202101));

	return 0;
}