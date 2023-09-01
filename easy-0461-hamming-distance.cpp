#include <climits>

class Solution {
public:
    template<typename T>
    inline int hammingDistance(T x, T y) noexcept {
        int count = 0;
        for (int i = 0; i < sizeof(T) * CHAR_BIT; i++) {
            int bit1 = (x >> i) & 1;
            int bit2 = (y >> i) & 1;
            if (bit1 != bit2) count++;
        }

        return count;
    }
};
