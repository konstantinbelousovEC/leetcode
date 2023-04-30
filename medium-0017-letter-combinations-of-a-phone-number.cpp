#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(const string& digits) {
        if (digits.empty()) return {};
        
        vector<string> result(1);
        for (char c : digits) {
            vector<string> current;
            for (char letter : letters_[c]) {
                for (auto&& str : result) {
                    current.push_back(str + letter);
                }
            }
            result = current;
        }
        
        return result;
    }


private:
    static unordered_map<char, string> letters_;

};

unordered_map<char, string> Solution::letters_ = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};