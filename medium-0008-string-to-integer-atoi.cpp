#include <cassert>
#include <string>

class Solution {
public:
    int myAtoi(const std::string& s) {
        if (s.empty()) return 0;
        int pos = 0;
        long result = 0;
        bool negative = false;

        if (s[pos] == ' ') {
            pos++;
            while (pos < s.size() && s[pos] == ' ') {
                pos++;
            }
        }
        if ( (s[pos] >= 65 && s[pos] <= 90) || (s[pos] >= 97 && s[pos] <= 122) || s[pos] == '.') {
            return 0;
        }
        if (s[pos] == '-') {
            negative = true;
            pos++;
        } else if (s[pos] == '+') {
            pos++;
        }

        if (pos < s.size()) {
            while (pos < s.size() && s[pos] >= 48 && s[pos] <= 57) {
                int digit = s[pos] - '0';
                result *= 10;
                result -= digit;
                if (result <= INT_MIN) {
                    result = INT_MIN + 1;
                    return negative ? result - 1 : -result;
                } else if (-result >= INT_MAX) {
                    result = INT_MIN;
                    return negative ? result + 1 : -result - 1;
                }
                pos++;
            }
        }

        return negative ? result : -result;
    }
};

/*
0 <= s.length <= 200
s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.
*/

int main() {
    Solution solution;

    // tests
    {
        std::string s = "42";
        assert(solution.myAtoi(s) == 42);
    }
    {
        std::string s = "-42";
        assert(solution.myAtoi(s) == -42);
    }
    {
        std::string s = "0";
        assert(solution.myAtoi(s) == 0);
    }
    {
        std::string s = "  0";
        assert(solution.myAtoi(s) == 0);
    }
    {
        std::string s = "  2350923";
        assert(solution.myAtoi(s) == 2350923);
    }
    {
        std::string s = "  -3453309";
        assert(solution.myAtoi(s) == -3453309);
    }
    {
        std::string s = "  -309 asdf fdsf";
        assert(solution.myAtoi(s) == -309);
    }
    {
        std::string s = "1009asdf fdsf";
        assert(solution.myAtoi(s) == 1009);
    }
    {
        std::string s = "      ";
        assert(solution.myAtoi(s) == 0);
    }
    {
        std::string s = "+-12";
        assert(solution.myAtoi(s) == 0);
    }
    {
        std::string s = "21474836460";
        assert(solution.myAtoi(s) == 2147483647);
    }
    {
        std::string s = "-91283472332";
        assert(solution.myAtoi(s) == -2147483648);
    }
    {
        std::string s = "2147483648";
        assert(solution.myAtoi(s) == 2147483647);
    }
    {
        std::string s = "2147483647";
        assert(solution.myAtoi(s) == 2147483647);
    }
    {
        std::string s = "-2147483647";
        assert(solution.myAtoi(s) == -2147483647);
    }

    return 0;
}