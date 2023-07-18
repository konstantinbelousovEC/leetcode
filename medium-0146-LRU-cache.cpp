class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) {}
    
    inline int get(int key) {
        auto hash_val = hash_.find(key);
        if (hash_val == hash_.end()) return -1;

        auto cache_pos = hash_val->second;
        int ret_val = cache_pos->second;

        if (cache_pos != cache_.begin()) cache_.splice(cache_.begin(), cache_, cache_pos, std::next(cache_pos));

        return ret_val;
    }
    
    inline void put(int key, int value) {
        auto hash_val = hash_.find(key);
        if (hash_val == hash_.end()) {
            if (is_full()) {
                hash_.erase(cache_.back().first);
                cache_.pop_back();
            }
            cache_.push_front({key, value});
            hash_[key] = cache_.begin();
        } else {
            auto cache_pos = hash_val->second;
            cache_pos->second = value;
            if (cache_pos != cache_.begin()) cache_.splice(cache_.begin(), cache_, cache_pos, std::next(cache_pos));
        }
    }

private:
    int capacity_;
    std::list<std::pair<int, int>> cache_;

    using ListIt = typename std::list<std::pair<int, int>>::iterator;
    std::unordered_map<int, ListIt> hash_;

    inline bool is_full() const noexcept {
        return capacity_ == cache_.size();
    }
};