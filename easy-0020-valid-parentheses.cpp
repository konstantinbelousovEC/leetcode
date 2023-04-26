#include <cassert>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) const {
        if (s.size() == 1) return false;

        std::stack<char> container;
        container.push(s.front());
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                container.push(s[i]);
                continue;
            }
            if (!container.empty() && container.top() == pairs_.at(s[i])) {
                container.pop();
            } else {
                container.push(s[i]);
            }
        }
        return container.empty();
    }
private:
    const std::unordered_map<char, char> pairs_ = {{')', '('}, {'}', '{'}, {']', '['}};
};

void Tests() {
    Solution solution;

    {
        string test_str = "()[]{}"s;
        assert(solution.isValid(test_str));
    }
    {
        string test_str = "()"s;
        assert(solution.isValid(test_str));
    }
    {
        string test_str = "(]"s;
        assert(!solution.isValid(test_str));
    }
    {
        string test_str = "(){}}{"s;
        assert(!solution.isValid(test_str));
    }
    {
        string test_str = "([])"s;
        assert(solution.isValid(test_str));
    }
    {
        string test_str = "([({[]})])"s;
        assert(solution.isValid(test_str));
    }
    {
        string test_str = "([([][]{}[])])"s;
        assert(solution.isValid(test_str));
    }
    {
        string test_str = "([({[)})])"s;
        assert(!solution.isValid(test_str));
    }
    cout << "Tests passed"s << endl;
}

int main() {
    Tests();
}