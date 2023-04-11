#include <string>

class Solution {
public:
    inline static int mySqrt(int x) {
        if (x == 0) return x;

        int first = 1, last = x;

        while (first <= last) {
            int mid = first + (last - first) / 2;
            if (mid  == x / mid) {
                return mid;
            } else if (mid > x / mid) {
                last = mid - 1;
            } else {
                first = mid + 1;
            }
        }
        return last;
    }
};

int main() {
    Solution solution;

    assert(solution.mySqrt(4) == 2);
    assert(solution.mySqrt(8) == 2);
    assert(solution.mySqrt(9) == 3);
    assert(solution.mySqrt(100) == 10);
}