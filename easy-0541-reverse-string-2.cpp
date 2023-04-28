#include <string>

using namespace std;

class Solution {
public:
    inline std::string reverseStr(std::string s, int k) {
        for (int start = 0; start < s.size(); start += (2 * k)) {
            int i = start, j = std::min(start + k - 1, static_cast<int>(s.size() - 1));
            while (i < j) {
                char tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
                i++;
                j--;
            }
        }
        return s;
    }
};

int main() {
    Solution solution;
    assert(solution.reverseStr("abcdefg", 2) == "bacdfeg");
    assert(solution.reverseStr("a", 2) == "a");
    assert(solution.reverseStr("abcd", 5) == "dcba");
    assert(solution.reverseStr("abcdefg", 3) == "cbadefg");
    assert(solution.reverseStr(
        "hyzqyljrnigxvdtneasepfahmtyhlohwxmkqcdfehybknvdmfrfvtbsovjbdhevlfxpdaovjgunjqlimjkfnqcqnajmebeddqsgl", 39) ==
        "fdcqkmxwholhytmhafpesaentdvxginrjlyqzyhehybknvdmfrfvtbsovjbdhevlfxpdaovjgunjqllgsqddebemjanqcqnfkjmi");
}