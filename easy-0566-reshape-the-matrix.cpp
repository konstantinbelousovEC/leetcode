class Solution {
public:
    std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>>& mat, int r, int c) {
        int mat_r = mat.size();
        int mat_c = mat.front().size();

        if (mat_r * mat_c != r * c) return mat;

        int mat_curr_r = 0;
        int mat_curr_c = 0;
        
        std::vector<std::vector<int>> res(r, std::vector(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                res[i][j] = mat[mat_curr_r][mat_curr_c];
                mat_curr_c++;
                if (mat_curr_c == mat_c) {
                    mat_curr_r++;
                    mat_curr_c = 0;
                }
            }
        }

        return res;
    }
};