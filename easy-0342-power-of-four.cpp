class Solution {
public:
    inline bool isPowerOfFour(int n) const noexcept {
        if (n <= 0) return false;
        return !(n & (n - 1)) && (n % 3 == 1);
    }
};