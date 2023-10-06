// Two Pointers | String

class Solution {
public:
    int countBinarySubstrings(string s) {
        int result = 0;
        int previous = 0;
        int current = 1;

        for (size_t i = 1; i < s.size(); i++) {
            if (s[i - 1] != s[i]) {
                result += std::min(previous, current);
                previous = current;
                current = 1;
            } else {
                current++;
            }
        }

        return result + std::min(previous, current);
    }
};

