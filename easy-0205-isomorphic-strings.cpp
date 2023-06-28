class Solution {
private:
    inline std::vector<int> count_symbols(const std::string& s) {
        std::vector<int> symbols; symbols.reserve(s.size());
        int symbols_index = 0;
        std::unordered_map<char, int> symbols_table;

        for (char c : s) {
            if (symbols_table.count(c) == 0) {
                symbols_table[c] = symbols_index;
                symbols_index++;
            }
        }

        for (char c : s) {
            symbols.push_back(symbols_table[c]);
        }

        return symbols;
    }

public:
    inline bool isIsomorphic(const std::string& s, const std::string& t) {
        std::vector<int> s_symbols = count_symbols(s);
        std::vector<int> t_symbols = count_symbols(t);

        return s_symbols == t_symbols;
    }
};