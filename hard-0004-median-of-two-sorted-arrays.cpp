// Array | Binary search | Divide and Conquer


// O(m + n) | Two pointers

class Solution {
public:
    double findMedianSortedArrays(const std::vector<int>& nums1, const std::vector<int>& nums2) const noexcept {
        int l_size = nums1.size();
        int r_size = nums2.size();
        int total_size = l_size + r_size;

        bool odd = total_size % 2 == 1;
    
        int prev{};
        int res{};

        int limit = odd ? (total_size + 1) / 2 : (total_size / 2) + 1;
        for (int i = 0, j = 0, k = 0; k < limit; k++) {
            prev = res;
            if (i < l_size && j < r_size) {
                if (nums1[i] < nums2[j]) {
                    res = nums1[i];
                    i++;
                } else {
                    res = nums2[j];
                    j++;
                }
            } else if (!(i < l_size) && j < r_size) {
                res = nums2[j];
                j++;
            } else if (i < l_size && !(j < r_size)) {
                res = nums1[i];
                i++;
            }
        }

        return odd ? res : (prev + res) / 2.0;
    }
};
