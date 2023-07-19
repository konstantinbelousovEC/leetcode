class Solution {
public:
    inline uint32_t reverseBits(uint32_t n) const noexcept {
        uint32_t result{};
        for (uint32_t i = 0; i < 32; i++) {
            uint32_t bit = (n >> i) & 1;
            result = result | (bit << (31 - i));
        }
        return result;
    }
};