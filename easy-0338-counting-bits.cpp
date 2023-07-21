class Solution {
private:
    constexpr static int bits_in_int = sizeof(int) * CHAR_BIT;
public:
    inline std::vector<int> countBits2(int n) const {
        std::vector<int> res;
        for (int i = 0; i <= n; i++) {
            int bits = 0, j = 0;
            while (j < bits_in_int) {
                if ((i >> j) & 1) bits++;
                j++;
            }
            res.push_back(bits);
        }
        return res;
    }

    inline std::vector<int> countBits(int n) const {
        std::vector<int> res;
        for (int i = 0; i <= n; i++) {
            res.push_back(__popcount(i));
        }
        return res;
    }
};