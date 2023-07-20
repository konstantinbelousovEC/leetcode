class Solution {
public:
    inline bool isPowerOfTwo(int n) const noexcept {
        if (n <= 0) return false;
        return !(n & (n - 1));
    }
};