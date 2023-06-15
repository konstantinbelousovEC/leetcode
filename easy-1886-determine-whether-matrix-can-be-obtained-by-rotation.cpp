class Solution {
public:
    inline void rotate(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < (n + 1) / 2; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                std::swap(matrix[n - 1 - j][i], matrix[n - 1 - i][n - j - 1]);
                std::swap(matrix[n - 1 - i][n - j - 1], matrix[j][n - 1 - i]);
                std::swap(matrix[j][n - 1 - i], matrix[i][j]);
            }
        }
    }

    inline bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if (mat == target) return true;

        int i = 0;
        while (i < 3) {
            rotate(mat);
            if (mat == target) return true;
            ++i;
        }

        return false;
    }
};