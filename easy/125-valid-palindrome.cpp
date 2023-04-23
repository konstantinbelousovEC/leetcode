#include <string>
#include <cassert>

class Solution {
public:
    inline static bool isPalindrome(const std::string& s) {
        std::string pure_str;

        int i = 0;
        while (i < s.size()) {
            if (std::isdigit(s[i]) || std::isalpha(s[i])) pure_str.push_back(std::tolower(s[i]));
            i++;
        }

        for (int i = 0, j = pure_str.size() - 1; i < pure_str.size() / 2; i++, j--) {
            if (pure_str[i] != pure_str[j]) return false;
        }

        return true;
    }
};

int main() {
    Solution solution;

    assert(solution.isPalindrome("A man, a plan, a canal: Panama"));
    assert(!solution.isPalindrome("race a car"));
    assert(solution.isPalindrome(" "));
}