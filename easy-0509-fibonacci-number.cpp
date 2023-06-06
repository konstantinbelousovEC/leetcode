// dynamic

class Solution {
public:
    inline int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        int n_fisrt = 0;
        int n_second = 1;

        int res = 0;
        for (int i = 2; i <= n; i++) {
            res = n_fisrt + n_second;
            n_fisrt = n_second;
            n_second = res;
        }

        return res;
    }
};

// recursive

class Solution {
public:
    inline int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return fib(n - 1) + fib(n - 2);
    }
};