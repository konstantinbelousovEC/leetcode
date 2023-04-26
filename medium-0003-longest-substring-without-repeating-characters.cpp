#include <string>
#include <cassert>

class Solution {
public:
    int lengthOfLongestSubstring(const std::string& s) {
        if (s.empty()) return 0;
        if (s.size() == 1u) return 1;
        std::string substring{s[0]};
        int max_substr_size = substring.size();

        for (int i = 1; i < s.size(); ++i) {
            auto pos = substring.find(s[i]);
            if (pos != std::string::npos) {
                substring = substring.substr(pos + 1, substring.size() - pos + 1);
            }
            substring.push_back(s[i]);
            if (substring.size() > max_substr_size) max_substr_size = substring.size();
        }

        return max_substr_size;
    }
};

int main() {
    using namespace std::string_literals;

    Solution solution;

    assert(solution.lengthOfLongestSubstring("abcabcbb"s) == 3); // "abc"
    assert(solution.lengthOfLongestSubstring("bbbbb"s) == 1); // "b"
    assert(solution.lengthOfLongestSubstring("pwwkew"s) == 3); // "wke"
    assert(solution.lengthOfLongestSubstring(" "s) == 1); //
    assert(solution.lengthOfLongestSubstring("au"s) == 2); // au
    assert(solution.lengthOfLongestSubstring("dvdf"s) == 3); // vdf
}