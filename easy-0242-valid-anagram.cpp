class Solution {
private:
    constexpr static size_t arr_size = 26;

public:
    bool isAnagram(const std::string& s, const std::string& t) {
        if (s.size() != t.size()) return false;

        std::array<int, arr_size> arr;
        arr.fill(0);

        for (int i = 0; i < s.size(); i++) {
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != 0) return false;
        }

        return true;
    }
};
