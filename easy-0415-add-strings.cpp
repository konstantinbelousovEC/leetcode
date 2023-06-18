class Solution {
public:
    inline std::string addStrings(std::string num1, std::string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;

        std::stringstream ss;

        while (i >= 0 || j >= 0 || carry > 0) {
            int digit1 = (i >= 0) ? num1[i] - '0' : 0;
            int digit2 = (j >= 0) ? num2[j] - '0' : 0;
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            int digit = sum % 10;
            ss << digit;
            i--;
            j--;
        }
        
        string result{std::move(ss.str())};
        std::reverse(result.begin(), result.end());

        return result;
    }
};
