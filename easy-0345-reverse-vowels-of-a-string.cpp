class Solution {
private:
    // const std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    inline bool is_vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

public:
    std::string reverseVowels(std::string s) {

        int i = 0, j = s.size() - 1;
        while (i < s.size() && i < j) {
            if (is_vowel(s[i])) {
                while (!is_vowel(s[j]) && i < j) j--;
                std::swap(s[i], s[j]);
                j--;
            }
            i++;
        }

        return s;
    }
};