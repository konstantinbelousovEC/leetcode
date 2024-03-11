// String, Stack
// https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(const std::string& s) {
        std::stack<char> stack;
        for (char c : s) {
            if (is_open_type(c)) stack.push(c);
            else {
                if (!stack.empty() && stack.top() == get_pair(c)) stack.pop();
                else return false;
            }
        }

        return stack.empty();
    }

private:
    inline char get_pair(char c) {
        switch (c) {
            case ')': return '(';
            case ']': return '[';
            case '}': return '{';

            default: return '-';
        }
    }

    inline bool is_open_type(char c) {
        switch (c) {
            case '(': return true;
            case '[': return true;
            case '{': return true;

            default: return false;
        }
    }
};

