class Solution {
public:
    inline int addDigits(int num) const {
        if (num == 0) return 0;
        if (num % 9 == 0) return 9;
        return num % 9;
    }
};