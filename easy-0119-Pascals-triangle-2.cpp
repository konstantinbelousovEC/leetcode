class Solution {
public:
    inline std::vector<int> get_row(int row_index) {
        std::vector<int> res;
        res.reserve(row_index);

        uint64_t prev_elem = 1;
        res.push_back(prev_elem);

        for (int i = 1; i <= row_index; i++) {
            uint64_t curr_elem = (prev_elem * (row_index - i + 1)) / i;
            res.push_back(curr_elem);
            prev_elem = curr_elem;
        }

        return res;
    }
};