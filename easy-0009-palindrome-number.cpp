// math

#include <cassert>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        if (x < 10) return true;
        
        long long reversed_num = 0;
        long long tmp_num = x;

        while (tmp_num > 0) {
            reversed_num *= 10;
            reversed_num += tmp_num % 10;
            tmp_num /= 10;
        }

        return x == reversed_num;
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
	assert(s.IsPolindrome(10122101));

	return 0;
}
