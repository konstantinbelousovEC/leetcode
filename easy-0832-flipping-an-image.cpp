class Solution {
public:
    std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& image) {
    	
        for (auto&& row : image) {
            std::reverse(row.begin(), row.end());
        }

        for (auto&& row : image) {
            for (size_t i = 0; i < row.size(); i++) {
                row[i] = row[i] ^ 1;
            }
        }

        return image;
    }
};