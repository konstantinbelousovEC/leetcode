#include <climits>

class Solution {
public:
    template<typename T>
    inline T findComplement(T num) noexcept {
        constexpr int digit_number = sizeof(T) * CHAR_BIT;
        std::bitset<digit_number> bitset(num);

        bool lead_zero = true;
        for(int i = digit_number - 1; i >= 0; i--) {
            if (bitset[i] != 0 && lead_zero) lead_zero = false;
            if (!lead_zero) bitset.flip(i);
        }

        return static_cast<int>(bitset.to_ulong());
    }
};
