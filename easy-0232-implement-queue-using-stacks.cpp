class MyQueue {
public:
    MyQueue() {}
    
    void push(int x) {
        swap_if_first_is_empty();
        first_.push(x);
    }
    
    int pop() {
        swap_if_first_is_empty();

        int tmp;
        int size = first_.size() - 1;
        move_all_elements(tmp, size);
        
        tmp = first_.top();
        first_.pop();

        move_all_elements(second_.size());

        return tmp;
    }
    
    int peek() {
        swap_if_first_is_empty();

        int tmp;
        int size = first_.size();
        move_all_elements(tmp, size);

        move_all_elements(second_.size());
        
        return tmp;
    }
    
    bool empty() const {
        return first_.empty() && second_.empty();
    }

private:
    std::stack<int> first_;
    std::stack<int> second_;

    void swap_if_first_is_empty() {
        if (first_.empty()) std::swap(first_, second_);
    }

    inline int move_element() {
        int tmp = first_.top();
        first_.pop();
        second_.push(tmp);
        return tmp;
    }

    inline void move_element_from_second() {
        int tmp = second_.top();
        second_.pop();
        first_.push(tmp);
    }

    void move_all_elements(int& tmp, int size) {
        while (size > 0) {
            tmp = move_element();
            size--;
        }
    }

    void move_all_elements(int size) {
        while (size > 0) {
            move_element_from_second();
            size--;
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