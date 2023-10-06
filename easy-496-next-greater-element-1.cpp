// Array | Hash Table | Stack | Monotonic Stack

class Solution {
public:
    // naive and slow solution
    std::vector<int> nextGreaterElement2(const std::vector<int>& nums1,
                                        const std::vector<int>& nums2) const noexcept
    {
        std::vector<int> res;
        res.reserve(nums1.size());
        
        for (size_t i = 0; i < nums1.size(); i++) {
            for (size_t j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    for (int k = j + 1; k < nums2.size(); k++) {
                        if (nums2[j] < nums2[k]) {
                            res.push_back(nums2[k]);
                            break;
                        }
                    }
                    if (res.size() != i + 1) res.push_back(-1);
                    break;
                }
            }
        }

        return res;
    }

    // using hash and stack solution
    std::vector<int> nextGreaterElement(const std::vector<int>& nums1,
                                        const std::vector<int>& nums2) const noexcept
    {
        std::unordered_map<int, int> hash;
        std::stack<int> stack;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!stack.empty() && stack.top() <= nums2[i])
                stack.pop();

            if (stack.empty()) hash[nums2[i]] = -1;
            else hash[nums2[i]] = stack.top();
            stack.push(nums2[i]);
        }

        std::vector<int> res;
        res.reserve(nums1.size());

        for (size_t i = 0; i < nums1.size(); i++) {
            res.push_back(hash[nums1[i]]);
        }

        return res;
    }
};

