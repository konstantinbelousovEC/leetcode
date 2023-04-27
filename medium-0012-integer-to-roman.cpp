#include <string>

using namespace std::string_literals;

class Solution {
public:
    inline std::string intToRoman(int num) {
        std::string result;
        int i = 0;
        while (num > 0) {
            if (num >= arabic[i]) {
                result.append(roman[i]);
                num -= arabic[i];
            } else {
                i++;
            }
        }
        return result;
    }
private:
    static std::vector<std::string> roman;
    static std::vector<int> arabic;
};

std::vector<std::string> Solution::roman = {"M"s,"CM"s,"D"s,"CD"s,"C"s,"XC"s,"L"s,"XL"s,"X"s,"IX"s,"V"s,"IV"s,"I"s};
std::vector<int> Solution::arabic = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};


int main() {
    Solution solution;

    assert(solution.intToRoman(3) == "III"s);
    assert(solution.intToRoman(58) == "LVIII"s);
    assert(solution.intToRoman(1994) == "MCMXCIV"s);
}