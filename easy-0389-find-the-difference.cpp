class Solution {
public:
    // naive and slow - NlogN
    char findTheDifference2(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if (s.size() > t.size()) std::swap(s, t);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) {
                return t[i];
            }
        }

        return t.back();
    }

    // fast - N
    char findTheDifference(const string& s, const string& t) {
        std::string str{s + t};

        char ch = 0;
        for (char c : str) {
            ch ^= c;
        }

        return ch;
    }
};