class Solution {
    using sz = std::vector<int>::size_type;
public:
    inline int missingNumber2(const std::vector<int>& nums) const noexcept {
        int real_sum = std::accumulate(nums.cbegin(), nums.cend(), 0);
        int should_be_sum = (nums.size() * (nums.size() + 1)) / 2;
        return should_be_sum - real_sum;
    }

    inline int missingNumber(const std::vector<int>& nums) const noexcept {
        int real{}, should_be{};
        sz size = nums.size();

        for (sz i = 0; i < size; i++) {
            real ^= nums[i];
            should_be ^= i;
        }

        return (should_be ^ size) ^ real;
    }
};