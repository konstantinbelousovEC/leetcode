class Solution {
public:
    // using std::upper_bound
    inline int search(vector<int>& nums, int target) {
        int idx = std::upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (idx > 0 && nums[idx - 1] == target) return idx - 1;
        return -1;
    }

    // common
    inline int search(vector<int>& nums, int target) {
        int start = 0;
        int to = nums.size() - 1;

        while (start <= to) {
            int mid = start + (to - start) / 2;
            if (nums[mid] < target) {
                start = mid + 1;
            } else if (nums[mid] > target) {
                to = mid - 1;
            } else {
                return mid;
            }
        }

        return -1;
    }
};