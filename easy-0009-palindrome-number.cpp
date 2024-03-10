// Math
// https://leetcode.com/problems/palindrome-number/description/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x >= 0 && x < 10) return true;

        long long reversed_num = 0;
        int x_copy = x;
        while (x_copy != 0) {
            reversed_num = (reversed_num * 10) + (x_copy % 10);
            x_copy /= 10;
        }

        return x == reversed_num;
    }
};

