class Solution {
    std::vector<std::string> result_;
    std::string str_;

    void generate(int left, int right) {
        if(right < left) return;
        if(left < 0 || right < 0) return;
        if(left == 0 && right == 0){
            result_.push_back(str_);
            return;
        }

        str_.push_back('(');
        generate(left - 1, right);
        str_.pop_back();

        str_.push_back(')');
        generate(left, right - 1);
        str_.pop_back();
    }

public:
    std::vector<std::string> generateParenthesis(int n) {
        result_.reserve(std::pow(2, n) * 2);
        generate(n, n);
        return result_;
    }
};
