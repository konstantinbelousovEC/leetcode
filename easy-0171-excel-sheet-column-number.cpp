class Solution {
public:
    int titleToNumber(const string& columnTitle) {
        int result = 0;
        for (char c : columnTitle) {
            result *= 26;
            result += c - 'A' + 1;
        }
        return result;
    }
};