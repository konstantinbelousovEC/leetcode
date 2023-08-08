class MyHashMap {
private:
    using list_of_pairs_t = std::list<std::pair<int, int>>;

    constexpr static int size = 2031;
    std::vector<list_of_pairs_t> hash_table_;

public:
    MyHashMap() : hash_table_(size) {}
    
    void put(int key, int value) {
        auto& bucket = find_bucket(key);
        auto it = find_elem_in_bucket(bucket, key);
        if (it != bucket.end()) it->second = value;
        else bucket.push_front({key, value});
    }
    
    int get(int key) const noexcept {
        auto& bucket = find_bucket(key);
        auto it = find_elem_in_bucket(bucket, key);
        if (it != bucket.end()) return it->second;
        else return -1;
    }
    
    void remove(int key) noexcept {
        auto& bucket = find_bucket(key);
        auto it = find_elem_in_bucket(bucket, key);
        if (it != bucket.end()) bucket.erase(it);
    }

private:
    list_of_pairs_t& find_bucket(int key) noexcept {
        size_t hash = std::hash<int>{}(key);
        return hash_table_[hash % size];
    }

    const list_of_pairs_t& find_bucket(int key) const noexcept {
        size_t hash = std::hash<int>{}(key);
        return hash_table_[hash % size];
    }

    list_of_pairs_t::iterator find_elem_in_bucket(list_of_pairs_t& list, int key) noexcept {
        list_of_pairs_t::const_iterator res = std::find_if(list.begin(), list.end(), [key](std::pair<int, int> p) {
            return p.first == key;
        });
        list_of_pairs_t::iterator non_const_res = remove_constness(list, res);
        return non_const_res;
    }

    list_of_pairs_t::const_iterator find_elem_in_bucket(const list_of_pairs_t& list, int key) const noexcept {
        return std::find_if(list.cbegin(), list.cend(), [key](std::pair<int, int> p) {
            return p.first == key;
        });
    }

    template <typename Container, typename ConstIterator>
    static typename Container::iterator remove_constness(Container& c, ConstIterator it) {
        return c.erase(it, it);
    }

};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */