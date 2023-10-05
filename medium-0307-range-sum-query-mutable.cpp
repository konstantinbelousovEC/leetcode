// Array | Design | Binary Index Tree | Segment Tree

// tests passed, but not accepted - time limit exceeded
class NumArray2 {
private:
    std::vector<int> nums_;
public:
    NumArray2(const std::vector<int>& nums)
        : nums_(nums) {}
    
    void update(int index, int val) noexcept {
        nums_[index] = val;
    }
    
    int sumRange(int left, int right) const noexcept {
        return std::accumulate(nums_.cbegin() + left, nums_.cbegin() + right + 1, 0);
    }
};

// Segment Tree
class NumArray {
private:
    size_t nums_size_;
    std::vector<int> segment_tree_;
    
    void buildSegmentTree(const std::vector<int>& nums,
						  size_t pos,
						  size_t left,
						  size_t right)
	{
        if (left == right) {
            segment_tree_[pos] = nums[left];
            return;
        }

        size_t mid = left + (right - left) / 2;
        buildSegmentTree(nums, 2 * pos + 1, left, mid);
        buildSegmentTree(nums, 2 * pos + 2, mid + 1, right);

		segment_tree_[pos] = segment_tree_[2 * pos + 1] +
							 segment_tree_[2 * pos + 2];
    }

    void updateSegmentTree(size_t pos,
						   size_t left,
						   size_t right,
						   size_t index,
						   int val)
	{
        if (index < left || index > right) return;
        
        if (left == right) {
            if(left == index) segment_tree_[pos] = val;
            return;
        }

        size_t mid = left + (right - left) / 2;
        updateSegmentTree(2 * pos + 1, left, mid, index, val);
        updateSegmentTree(2 * pos + 2, mid + 1, right, index, val);

		segment_tree_[pos] = segment_tree_[2 * pos + 1] +
							 segment_tree_[2 * pos + 2];
    }

    int getSumRange(size_t qlow,
					size_t qhigh,
					size_t low,
					size_t high,
					size_t pos) const
	{
        if (qlow <= low && qhigh >= high) return segment_tree_[pos];
        if (qlow > high || qhigh < low) return 0;

        size_t mid = low + (high - low) / 2;
        return getSumRange(qlow, qhigh, low, mid, 2 * pos + 1) +
               getSumRange(qlow, qhigh, mid + 1, high, 2 * pos + 2);
    }

public:
    NumArray(const std::vector<int>& nums)
        : nums_size_(nums.size()), segment_tree_(nums_size_ * 4, 0) {
            buildSegmentTree(nums, 0, 0, nums_size_ - 1);
        }
    
    void update(size_t index, int val) noexcept {
        if (nums_size_ == 0) return;
        updateSegmentTree(0, 0, nums_size_ - 1, index, val);
    }
    
    int sumRange(size_t left, size_t right) const noexcept {
        if (nums_size_ == 0) return 0;
        return getSumRange(left, right, 0, nums_size_ - 1, 0);
    }
};

