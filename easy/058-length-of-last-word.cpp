#include <iostream>
#include <string>
#include <cassert>

class Solution {
public:
    inline int lengthOfLastWord(const std::string& s) {
        // int last = s.find_last_not_of(' ');
        int last = s.size() - 1;
        for (; s[last] == ' '; --last) {}

        int first = last;
        for (; s[first] != ' ' && first != 0; --first) {}

        if (s[first] != ' ' && first != 0) {
            return last - first - 1;
        } else if (s[first] == ' ') {
            return last - first;
        } else {
            return last - first + 1;
        }
    }
};

int main() {
    using namespace std::string_literals;
    
    Solution solution;

    {
        std::string input = "Hello World"s;
        assert(solution.lengthOfLastWord(input) == 5);
    }
    {
        std::string input = "   fly me   to   the moon  "s;
        assert(solution.lengthOfLastWord(input) == 4);
    }
    {
        std::string input = "luffy is still joyboy"s;
        assert(solution.lengthOfLastWord(input) == 6);
    }
    {
        std::string input = "luf"s;
        assert(solution.lengthOfLastWord(input) == 3);
    }
    {
        std::string input = "a"s;
        assert(solution.lengthOfLastWord(input) == 1);
    }
    {
        std::string input = " a"s;
        assert(solution.lengthOfLastWord(input) == 1);
    }
    {
        std::string input = "  a"s;
        assert(solution.lengthOfLastWord(input) == 1);
    }

    return 0;
}