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