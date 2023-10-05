// array | design | preffix sum

// naive
class NumArray3 {
private:
    const std::vector<int> nums_;
public:
    NumArray3(const std::vector<int>& nums)
        : nums_(nums) {}
    
    int sumRange(int left, int right) const noexcept {
        return std::accumulate(nums_.begin() + left, nums_.begin() + right + 1, 0);
    }
};

// preffix sum naive
class NumArray2 {
private:
    std::vector<int> nums_;
public:
    NumArray2(const std::vector<int>& nums) {
        nums_.reserve(nums.size());
        
        nums_.push_back(nums[0]);

        for (size_t i = 1; i < nums.size(); i++) {
            nums_.push_back(nums[i] + nums_[i - 1]);
        }
    }
    
    int sumRange(int left, int right) const noexcept {
        if (left == 0) return nums_[right];
        return nums_[right] - nums_[left - 1];
    }
};

// preffix sum STL
class NumArray {
private:
    std::vector<int> partial_sum_;
public:
    NumArray(std::vector<int>& nums)
        : partial_sum_(nums.size() + 1, 0)
    {
        std::partial_sum(nums.cbegin(), nums.cend(), partial_sum_.begin() + 1);
    }
    
    int sumRange(int left, int right) const noexcept {
        return partial_sum_[right + 1] - partial_sum_[left];
    };
};

