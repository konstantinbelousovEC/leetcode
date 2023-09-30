class Solution {
public:
    int countPrimes(int n) {
        bool sieve[n + 1];
        std::memset(sieve, true, sizeof(sieve));

        int count = 0;
  
        for (size_t i = 2; i < n; i++) {
            if (sieve[i]) {
                count++;
                for (size_t y = i * i; y < n; y += i) {
                    sieve[y] = false;
                };
            };
        };
        
        return count;
    }
};

