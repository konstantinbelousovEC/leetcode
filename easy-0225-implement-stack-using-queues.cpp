

class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        swap_if_first_is_empty();
        first_.push(x);
    }

    int pop() {
        swap_if_first_is_empty();

        int tmp;
        iterate(tmp, first_.size() - 1);

        tmp = first_.front();
        first_.pop();

        return tmp;
    }

    int top() {
        swap_if_first_is_empty();

        int tmp;
        iterate(tmp, first_.size());

        return tmp;
    }

    inline bool empty() const {
        return first_.empty() && second_.empty();
    }

private:
    std::queue<int> first_;
    std::queue<int> second_;

    inline void swap_if_first_is_empty() {
        if (first_.empty()) std::swap(first_, second_);
    }

    inline int move_elements() {
        auto tmp = first_.front();
        first_.pop();
        second_.push(tmp);
      
        return tmp;
    }

    inline void iterate(int& tmp, int size) {
        while (size > 0) {
            tmp = move_elements();
            size--;
        }
    }
};
