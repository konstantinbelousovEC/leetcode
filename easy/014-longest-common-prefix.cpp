#include <vector>
#include <string>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp = strs.front();
        for (int i = 1; i < strs.size(); i++) {
            if (lcp.size() > strs[i].size()) lcp.resize(strs[i].size());
            if (lcp.empty()) break;

            for (int j = 0; j < lcp.size(); j++) {
                if (lcp[j] != strs[i][j]) {
                    lcp.resize(j);
                    break;
                }
            }
        }
        return lcp;
    }
};

void TestSolution() {
    Solution solution;
    
    {
        vector<string> v{"flower"s, "flow"s, "flight"s};
        assert(solution.longestCommonPrefix(v) == "fl"s);
    }

    {
        vector<string> v{"chicken"s, "chickens"s, "chicks"s};
        assert(solution.longestCommonPrefix(v) == "chick"s);
    }

    {
        vector<string> v{"chicken"s, "dog"s, "chicks"s};
        assert(solution.longestCommonPrefix(v) == ""s);
    }

    {
        vector<string> v{"hi"s};
        assert(solution.longestCommonPrefix(v) == "hi"s);
    }

    {
        vector<string> v{""s, "b"};
        assert(solution.longestCommonPrefix(v) == ""s);
    }

    cout << "Tests passed"s << endl;
}

int main() {
    TestSolution(); 
}