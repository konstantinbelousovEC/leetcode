class Solution {
public:
    bool isHappy(int n) const {
        std::unordered_set<int> hash;
        
        while (hash.count(n) == 0) {
            hash.insert(n);

            std::string n_str{std::to_string(n)};
            n = 0;
            for (char digit : n_str) {
                n += std::pow(digit - 48, 2);
            }

            if (n == 1) return true;
        }

        return false;
    }
};