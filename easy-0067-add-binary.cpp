#include <string>

class Solution {
public:
    inline static std::string addBinary(const std::string& a, const std::string& b) {
        std::string result;
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0)
                carry += a[i--] - '0';
            if (j >= 0)
                carry += b[j--] - '0';
            result += carry % 2 + '0';
            carry /= 2;
        }

        reverse(begin(result), end(result));
        return result;
    }
};

int main() {
    using namespace std::string_literals;

    Solution solution;

    assert(solution.addBinary("11"s, "1"s) == "100");
    assert(solution.addBinary("1010"s, "1011"s) == "10101");
}