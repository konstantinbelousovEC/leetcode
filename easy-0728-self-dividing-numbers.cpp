class Solution {
    inline bool isSelfDividing(int i) const noexcept {
        int tmp_i = i;
        while (tmp_i > 0) {
            int digit = tmp_i % 10;
            if (digit == 0 || i % digit != 0) return false;
            tmp_i /= 10;
        }
        return true;
    }

public:
    std::vector<int> selfDividingNumbers(int left, int right) const noexcept {
        std::vector<int> res; res.reserve(right - left + 1);

        for (int i = left; i <= right; i++) {
            if (isSelfDividing(i)) res.push_back(i);
        }

        return res;
    }
};
