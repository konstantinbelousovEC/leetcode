class Solution {
private:
    int factorial(int n) const noexcept {
        int fact = 1;
	    while (n > 1) {
		    fact *= n;
		    n--;
	    }
	    return fact;
    }

    void permute(std::vector<int>& nums, std::vector<std::vector<int>>& res, int index) const {
        if(index >= nums.size()) {
            res.push_back(nums);
            return;
        }

        for(int i = index; i < nums.size(); i++) {
            std::swap(nums[index], nums[i]);
            permute(nums, res, index + 1);
            std::swap(nums[index], nums[i]);
        }
    }

public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) const {
        vector<vector<int>> res;
        res.reserve(factorial(nums.size()));

        permute(nums, res, 0);

        return res;
    }
};

