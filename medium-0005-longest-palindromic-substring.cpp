#include <string>
#include <cassert>

class Solution {
public:
    std::string longestPalindrome(const std::string& s) {
        std::string res;
        for (int i = 0; i < s.size(); i++) {
            int left = i;
            int right;
            if (s.size() % 2 != 0) {
                right = i;
            } else {
                right = i + 1;
            }
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                if (right - left + 1 > res.size()) {
                    res = s.substr(left, right - left + 1);
                }
                left--;
                right++;
            }    
        }
        return res.empty() ? std::string{s[0]} : res;
    }
};

int main() {
    using namespace std::string_literals;

    Solution solution;

    assert(solution.longestPalindrome("babad"s) == "bab"s);
    assert(solution.longestPalindrome("cbbd"s) == "bb"s);
}