class Solution {
private:
    std::string make_range(int l, int r) const {
        std::string range;
        range.append(std::to_string(l));
        if (l != r) range.append("->").append(std::to_string(r));
        return range;
    }

public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) const {
        std::vector<std::string> res;
        if (nums.empty()) return res;
        res.reserve(20);

        size_t nums_size = nums.size();

        for (size_t i = 0; i < nums_size; i++) {
            int l = nums[i];

            while (i < nums_size - 1 && nums[i] + 1 == nums[i + 1])
                i++;

            int r = nums[i];

            res.push_back(make_range(l, r));
        }

        return res;
    }
};

