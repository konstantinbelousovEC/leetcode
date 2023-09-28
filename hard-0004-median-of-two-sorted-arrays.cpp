// Array | Binary search | Divide and Conquer


class Solution {
public:
    // O(m + n)
    double findMedianSortedArrays2(const std::vector<int>& nums1, const std::vector<int>& nums2) const noexcept {
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

    // O(log(m + n))
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) const noexcept {
        if (nums1.size() > nums2.size()) std::swap(nums1, nums2);

        int m = nums1.size(), n = nums2.size();
        int left = 0, right = m;

        while (left <= right) {
            int partition_A = (left + right) / 2;
            int partition_B = (m + n + 1) / 2 - partition_A;
            
            int max_left_A = (partition_A == 0) ? INT_MIN : nums1[partition_A - 1];
            int min_right_A = (partition_A == m) ? INT_MAX : nums1[partition_A];
            int max_left_B = (partition_B == 0) ? INT_MIN : nums2[partition_B - 1];
            int min_right_B = (partition_B == n) ? INT_MAX : nums2[partition_B];
            
            if (max_left_A <= min_right_B && max_left_B <= min_right_A) {
                if ((m + n) % 2 == 0) {
                    return (max(max_left_A, max_left_B) + min(min_right_A, min_right_B)) / 2.0;
                } else {
                    return max(max_left_A, max_left_B);
                }
            } else if (max_left_A > min_right_B) {
                right = partition_A - 1;
            } else {
                left = partition_A + 1;
            }
        }
        
        return 0.0;
    }
};
