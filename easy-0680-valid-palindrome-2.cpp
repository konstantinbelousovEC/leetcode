class Solution {
private:
    template<bool second_chance>
    inline bool is_palindrome(const std::string& s, size_t i, size_t j) {
        while (i < j) {
            if (s[i] != s[j]) {
                if constexpr (second_chance) {
                    return is_palindrome<false>(s, i + 1, j) || is_palindrome<false>(s, i, j - 1);
                } else {
                    return false;
                }
            }
            i++;
            j--;
        }
        return true;
    }

public:
    bool validPalindrome(const std::string& s) {
        return is_palindrome<true>(s, 0, s.size() - 1);
    }
};