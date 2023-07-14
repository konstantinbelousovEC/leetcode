class Solution {
private:
    template<bool P>
    inline bool traverse(const std::string& word, int pos) {
        while (pos < word.size()) {
            if constexpr (P) {
                if (std::isupper(word[pos])) return false;
            } else {
                if (!std::isupper(word[pos])) return false;
            }
            pos++;
        }
        return true;
    }

public:
    bool detectCapitalUse(const std::string& word) {
        if (word.size() == 1) return true;

        if (std::isupper(word.front())) {
            if (std::isupper(word[1])) {
                return traverse<false>(word, 2);
            } else {
                return traverse<true>(word, 2);
            }
        } else {
            return traverse<true>(word, 1);
        }

        return true;
    }
};