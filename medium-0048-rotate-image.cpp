class Solution {
public:

    inline void transpose(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i + 1; j < matrix.size(); j++) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    
    inline void reflect(vector<vector<int>>& matrix) {
        std::for_each(matrix.begin(), matrix.end(), [](vector<int>& row) {
            std::reverse(row.begin(), row.end());
        });
    }

    inline void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reflect(matrix);
    }
};

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < (n + 1) / 2; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                std::swap(matrix[n - 1 - j][i], matrix[n - 1 - i][n - j - 1]);
                std::swap(matrix[n - 1 - i][n - j - 1], matrix[j][n - 1 - i]);
                std::swap(matrix[j][n - 1 - i], matrix[i][j]);
            }
        }
    }
};