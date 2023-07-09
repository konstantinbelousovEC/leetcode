auto l = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();

class Solution {
private:
    constexpr static int FAIL = -1;
public:
    inline int firstUniqChar(string s) {
        std::array<int, 26> arr;
        arr.fill(0);

        for (int i = 0; i < s.size(); i++) {
            arr[s[i] - 'a']++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (arr[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return FAIL;
    }
};