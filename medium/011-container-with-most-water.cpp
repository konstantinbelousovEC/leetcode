class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        
        int i = 0, j = height.size() - 1;
        while (i < j) {
            int y = height[i] > height[j] ? height[j] : height[i];
            int x = j - i;
            int area = x * y;
            max_area = area > max_area ? area : max_area;
            if (height[i] > height[j]) {
                j--;
            } else {
                i++;
            }
        }

        return max_area;
    }
};