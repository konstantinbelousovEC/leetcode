class Solution {
public:
    std::string licenseKeyFormatting(const std::string& s, int k) {
        std::string res;
        res.reserve(s.size());

        int count = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != '-') {
                if (count > 0 && count % k == 0) res.push_back('-');
                res.push_back(std::toupper(s[i]));
                count++;
            }
        }

        std::reverse(res.begin(), res.end());

        return res;
    }
};