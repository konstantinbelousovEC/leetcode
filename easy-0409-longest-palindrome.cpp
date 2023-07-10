class Solution {
public:
    inline int longestPalindrome(const std::string& s) {
        std::unordered_map<char, int> hash_t;
        
        int count = 0;
        
        for (char ch : s) {
            hash_t[ch]++;
            if (hash_t[ch] % 2 == 1) count++;
            else count--;
        }

        if (count > 1) return s.size() - count + 1;

        return s.size();
    }
};