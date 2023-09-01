#include <climits>

class Solution {
public:
    template<typename T>
    inline int totalHammingDistance(const std::vector<T>& nums) noexcept {
        int N = sizeof(T) * CHAR_BIT;
        std::vector<int> v(N, 0);

        for (auto num : nums) {
            for (int b = 0; b < N; b++) {
                if (num & (1 << b)) v[b]++;
            }
        }
        
        int counter{0};
        size_t size{nums.size()};
        for (auto bits : v) {
            counter += bits * (size - bits);
        }

        return counter;
    }
};
