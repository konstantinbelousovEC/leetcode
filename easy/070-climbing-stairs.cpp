#include <cassert>

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        int prev_0 = 1;
        int prev_1 = 2;

        for (int i = 2; i < n; i++) {
            int next = prev_0 + prev_1;
            prev_0 = prev_1;
            prev_1 = next;
        }

        return prev_1;
    }
};

int main() {
    Solution solution;
    assert(solution.climbStairs(2) == 2);
    assert(solution.climbStairs(3) == 3);
    assert(solution.climbStairs(4) == 5);

    return 0;
}