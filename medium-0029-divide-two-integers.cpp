class Solution {
public:
    static int divide(int dividend, int divisor) noexcept {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        int64_t dividend64 = std::llabs(dividend);
        int64_t divisor64 = std::llabs(divisor);

        int64_t quotient = 0;
        while (dividend64 >= divisor64) {
            int64_t temp = divisor64, multiple = 1;
            while (dividend64 >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dividend64 -= temp;
            quotient += multiple;
        }

        quotient *= sign;

        return quotient;
    }
};

