class Solution {
public:
    inline std::string toLowerCase(std::string s) {
        for (int i = 0; i < s.size(); i++) {
            if (std::isupper(s[i])) {
                s[i] = s[i] + 32; // s[i] = std::tolower(s[i]);
            }
        }

        return s;
    }
};