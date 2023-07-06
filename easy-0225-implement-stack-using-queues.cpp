class MyStack {
public:
    MyStack() = default;

    void push(int x) {
        q2_.push(x);
        top_ = x;

        while(!q1_.empty()) {
            int tmp = q1_.front();
            q1_.pop();
            q2_.push(tmp);
        }
        std::swap(q1_, q2_);
    }

    int pop() {
        int res = top_;
        q1_.pop();
        if (!q1_.empty()) top_ = q1_.front();
        return res;
    }

    int top() const noexcept {
        return top_;
    }

    inline bool empty() const noexcept {
        return q1_.empty();
    }

private:
    std::queue<int> q1_;
    std::queue<int> q2_;
    int top_;

};