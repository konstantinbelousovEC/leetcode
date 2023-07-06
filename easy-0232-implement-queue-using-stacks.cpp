class MyQueue {
public:
    MyQueue() {}
    
    void push(int x) {
        if (s1_.empty()) front = x;
        moving_elements(s1_, s2_);    
        s2_.push(x);
        moving_elements(s2_, s1_);
    }
    
    int pop() {
        int res = s1_.top();
        s1_.pop();
        if (!s1_.empty()) front = s1_.top();
        return res;
    }
    
    int peek() const noexcept {
        return front;
    }
    
    bool empty() const noexcept {
        return s1_.empty() && s2_.empty();
    }

private:
    std::stack<int> s1_;
    std::stack<int> s2_;
    int front;

    static inline void moving_elements(std::stack<int>& s1, std::stack<int>& s2) {
        while (!s1.empty()) {
            int tmp = s1.top();
            s2.push(tmp);
            s1.pop();
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */