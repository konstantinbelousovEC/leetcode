class Solution {
public:
    inline bool isPerfectSquare(int num) {
        if (num == 1) return true;

        double half = num / 2.0;
        double tmp = 0.0;

        while (half != tmp) {
            tmp = half;
            half = (num / tmp + tmp) / 2;
        }

        return half == ceil(half);
    }
};