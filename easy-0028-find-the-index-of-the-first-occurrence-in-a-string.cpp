#include <iostream>
#include <string>
#include <cassert>

class Solution1 {
public:
    int strStr(const std::string& haystack, const std::string& needle) {
        size_t res = haystack.find(needle);
        if (res != std::string::npos) return res;
        return -1;
    }
};

class Solution2 { // works faster than Solution1
public:
    int strStr(const std::string& haystack, const std::string& needle) {
        int haystack_size = haystack.size();
        int needle_size = needle.size();
        if (haystack_size < needle_size) return -1;
        for (int i = 0; i <= haystack_size - needle_size; ++i) {
            int j = 0;
            while (j < needle_size && haystack[i + j] == needle[j]) {
                j++;
                if (j == needle_size) return i;
            }
        }
        return -1;
    }
};

int main() {
    using namespace std::string_literals;

    {
        Solution1 solution;
        assert(solution.strStr("sadbutsad"s, "sad"s) == 0);
        assert(solution.strStr("assadbutsad"s, "sad"s) == 2);
        assert(solution.strStr("leetcode"s, "leeto"s) == -1);
    }

    {
        Solution2 solution;
        assert(solution.strStr("sadbutsad"s, "sad"s) == 0);
        assert(solution.strStr("assadbutsad"s, "sad"s) == 2);
        assert(solution.strStr("leetcode"s, "leeto"s) == -1);
    }
}