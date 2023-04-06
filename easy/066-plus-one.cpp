#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        if (digits[i] != 9) {
            ++digits[i];
            return digits;
        } else {
            while (digits[i] == 9) {
                if (i == 0) {
                    digits[i] = 0;
                    digits.insert(digits.begin(), 1);
                    return digits;
                } else {
                    digits[i] = 0;
                    --i;
                }
            }
            ++digits[i];
        }
        return digits;
    }
};

int main() {
    Solution solution;

    {
        std::vector<int> input{1, 2, 3};
        std::vector<int> res{1, 2, 4};
        assert(solution.plusOne(input) == res);
    }
    {
        std::vector<int> input{1, 9, 9};
        std::vector<int> res{2, 0, 0};
        assert(solution.plusOne(input) == res);
    }
    {
        std::vector<int> input{9};
        std::vector<int> res{1, 0};
        assert(solution.plusOne(input) == res);
    }

    std::cout << "Tests are passed"s << std::endl;
}