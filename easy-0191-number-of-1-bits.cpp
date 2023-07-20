class Solution {
public:
    inline int hammingWeight2(uint32_t n) const noexcept {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if (((n >> i) & 1) == 1) res++;
        }

        return res;
    }

    inline int hammingWeight(uint32_t n) const noexcept {
        int res = 0;
        while (n != 0) {
            if (n & 1) res++;
            n = n >> 1;
        }
        return res;
    }
};