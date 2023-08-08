class Solution {
private:
    struct trustness_t {
        std::deque<int> i_trust_{};
        std::deque<int> who_trust_me_{};
    };

public:
    int findJudge2(int n, const std::vector<std::vector<int>>& trust) const noexcept {
        if (trust.empty() && n == 1) return n;

        std::unordered_map<int, trustness_t> hash_table;

        for (auto&& relation : trust) {
            hash_table[relation.front()].i_trust_.push_back(relation.back());
            hash_table[relation.back()].who_trust_me_.push_back(relation.front());
        }

        auto iter = std::find_if(hash_table.begin(),
                                 hash_table.end(),
                                 [n](const std::pair<int, trustness_t>& person_info) {
                                     auto&& person = person_info.second;
                                     return person.i_trust_.empty() &&
                                            person.who_trust_me_.size() == n - 1;
                                 });

        return iter == hash_table.end() ? -1 : iter->first;
    }

    int findJudge(int n, const std::vector<std::vector<int>>& trust) const noexcept {
        if (trust.empty() && n == 1) return n;

        std::vector<int> indegree(n + 1, 0);
        std::vector<int> outdegree(n + 1, 0);

        for (auto&& person_info : trust) {
            indegree[person_info.front()]++;
            outdegree[person_info.back()]++;
        }

        for (int i = 0; i < n + 1; i++) {
            if (indegree[i] == 0 && outdegree[i] == n - 1) return i;
        }

        return -1;
    }
};
