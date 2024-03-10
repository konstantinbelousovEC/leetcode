// Hash Table, Math, String
// https://leetcode.com/problems/roman-to-integer/description/

class Solution {
public:
    int romanToInt(const std::string& s) {
        std::vector<int> nums;
        nums.reserve(s.size());

        for (char c : s)
            nums.push_back(romanSymbolToDigit(c));

        int result = 0;
        int i = 0;
        int n = nums.size();
        while (i < n) {
            if ((i == n - 1) || (nums[i] >= nums[i + 1])) {
                result += nums[i];
                i++;
            } else {
                result += nums[i + 1] - nums[i];
                i += 2;
            }
        }

        return result;
    }

private:
    inline int romanSymbolToDigit(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }

        return 0;
    }

};

