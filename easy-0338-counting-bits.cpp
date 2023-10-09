// Dynamic Programming | Bit Manipulation

class Solution {
private:
    constexpr static int bits_in_int = sizeof(int) * CHAR_BIT;
public:
	std::vector<int> countBits4(int n) const {
		std::vector<int> res;
		res.reserve(n + 1);
		for (int i = 0; i <= n; i++) {
			int count = 0;
			for(int j = i; j > 0; j = j & (j - 1)) {
				count += 1;
			}
			res.push_back(count);
		}
		return res;
	}

	std::vector<int> countBits3(int n) const {
		std::vector<int> res(n + 1, 0);
		for(int i = 1; i <= n; i++)
			res[i] = res[i / 2] + (i % 2);

		return res;
	}

    inline std::vector<int> countBits2(int n) const {
        std::vector<int> res;
        for (int i = 0; i <= n; i++) {
            int bits = 0, j = 0;
            while (j < bits_in_int) {
                if ((i >> j) & 1) bits++;
                j++;
            }
            res.push_back(bits);
        }
        return res;
    }

    inline std::vector<int> countBits(int n) const {
        std::vector<int> res;
        for (int i = 0; i <= n; i++) {
            res.push_back(__popcount(i));
        }
        return res;
    }
};

