#include <iostream>
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        std::vector<int> nums1_copy(m);
        for (int i = 0; i < m; i++) {
            nums1_copy[i] = nums1[i];
        }

        int i = 0, j = 0, k = 0;
        while (i < m && j < n) {
            if (nums1_copy[i] <= nums2[j]) {
                nums1[k] = nums1_copy[i];
                i++;
            } else {
                nums1[k] = nums2[j];
                j++;
            }
            k++;
        }

        while (i < m) {
            nums1[k] = nums1_copy[i];
            i++;
            k++;
        }

        while (j < n) {
            nums1[k] = nums2[j];
            j++;
            k++;
        }
    }
};

int main() {
    std::vector<int> arr1 = { 1, 2, 3, 0, 0, 0};
    std::vector<int> arr2 = { 2, 5, 6};

    Solution solution;
    solution.merge(arr1, 3, arr2, 3);

    for (auto elem : arr1) {
        std::cout << elem << " ";
    }

    return 0;
}