#include <string>
#include <vector>

class Solution {
public:
    inline static int longestCommonSubsequence(const std::string& str_1, const std::string& str_2) {
        int size_1 = str_1.size();
        int size_2 = str_2.size();

        std::vector<std::vector<int>> table(size_1 + 1, std::vector<int>(size_2 + 1));

        for (int m = 1; m <= size_1; m++) {
            for (int n = 1; n <= size_2; n++) {
                if (str_1[m - 1] == str_2[n - 1]) {
                    table[m][n] = table[m - 1][n - 1] + 1;
                } else {
                    table[m][n] = table[m - 1][n] > table[m][n - 1] ? table[m - 1][n] : table[m][n - 1];
                }
            }
        }

        return table[size_1][size_2];
    }
};

int main() {
    Solution solution;

    assert(solution.longestCommonSubsequence("abcde", "ace") == 3);
    assert(solution.longestCommonSubsequence("abc", "abc") == 3);
    assert(solution.longestCommonSubsequence("abc", "def") == 0);
}