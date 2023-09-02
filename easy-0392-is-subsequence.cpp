class Solution {
public:
    inline bool isSubsequence(const std::string& sub,
                              const std::string& str) noexcept
    {
        if (sub.empty()) return true;
        if (sub.size() > str.size()) return false;

        int sub_index = 0;
        for (char c : str) {
            if (c == sub[sub_index])
                sub_index++;
        }

        return sub_index == sub.size();
    }
};
