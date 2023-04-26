#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
    int searchInsert(const std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int closest = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                closest = mid + 1;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return closest;
    }
};

int main() {
    Solution solution;
    {
        std::vector<int> v{1,3,5,6};
        assert(solution.searchInsert(v, 5) == 2);
        assert(solution.searchInsert(v, 2) == 1);
        assert(solution.searchInsert(v, 7) == 4);
    }
}