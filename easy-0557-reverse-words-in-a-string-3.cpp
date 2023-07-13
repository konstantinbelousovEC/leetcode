class Solution {
public:

    string reverseWords(std::string s) {
        int i = 0;
        int j = s.find(" "s);

        while (j != std::string::npos) {
            std::reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
            j = s.find(" "s, i);
        }

        std::reverse(s.begin() + i, s.end());
        
        return s;
    }
};