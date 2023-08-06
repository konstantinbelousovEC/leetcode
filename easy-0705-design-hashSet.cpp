class MyHashSet {
private:
    constexpr static int size = 2031;
    std::vector<std::list<int>> hash_table_;
    
private:
    using list_iter_t = std::list<int>::const_iterator;
    using list_t = std::list<int>;

    inline list_t& find_bucket(int key) noexcept {
        size_t hash = std::hash<int>{}(key);
        auto& list = hash_table_[hash % size];
        return list;
    }

    inline const list_t& find_bucket(int key) const noexcept {
        size_t hash = std::hash<int>{}(key);
        const auto& list = hash_table_[hash % size];
        return list;
    }

    inline list_iter_t find_elem(int key) noexcept {
        auto& list = find_bucket(key);
        return std::find_if(list.cbegin(), list.cend(), [key](int elem){
            return elem == key;
        });
    }

    inline const list_iter_t find_elem(int key) const noexcept {
        const auto& list = find_bucket(key);
        return std::find_if(list.cbegin(), list.cend(), [key](int elem){
            return elem == key;
        });
    }

public:
    MyHashSet() : hash_table_(size) {}
    
    void add(int key) {
        auto& list = find_bucket(key);
        auto it = find_elem(key);
        if (it == list.cend()) list.push_front(key);
    }
    
    void remove(int key) {
        auto& list = find_bucket(key);
        auto it = find_elem(key);
        if (it != list.cend()) list.erase(it);
    }
    
    bool contains(int key) const {
        auto& list = find_bucket(key);
        auto it = find_elem(key);
        return it != list.cend();
    }

};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */