class Solution {
public:
    inline vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        nums1.erase(std::unique(nums1.begin(), nums1.end()), nums1.end());
        nums2.erase(std::unique(nums2.begin(), nums2.end()), nums2.end());

        size_t size_1 = nums1.size();
        size_t size_2 = nums2.size();

        vector<int> res;
        res.reserve(size_1 > size_2 ? size_2 : size_1);

        if (size_1 > size_2) std::swap(nums1, nums2);

        for (int elem : nums1) {
            if (std::binary_search(nums2.begin(), nums2.end(), elem)) res.push_back(elem);
        }

        return res;
    }
};