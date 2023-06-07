class Solution {
public:
    inline vector<int> constructRectangle(int area) {
        int root = std::sqrt(area);
        
        for (int width = root; width >= 1; width--) {
            if (area % width == 0) {
                int length = area / width;
                return {width > length ? width : length, width > length ? length : width};
            }
        }
        
        return {};
    }
};