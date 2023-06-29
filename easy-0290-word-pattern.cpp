class Solution {
private:
    template<typename Iterator>
    std::vector<int> make_array_of_symbols_indexes(Iterator first, Iterator last) {
        int symbol_index = 0;
        std::unordered_map<typename Iterator::value_type, int> symbol_indexes;

        std::for_each(first, last, [&](typename Iterator::value_type element) {
            if (symbol_indexes.count(element) == 0) {
                symbol_indexes[element] = symbol_index;
                symbol_index++;
            }
        });

        std::vector<int> arr_of_symbol_indexes;
        arr_of_symbol_indexes.reserve(std::distance(first, last));

        std::for_each(first, last, [&](typename Iterator::value_type element){
            arr_of_symbol_indexes.push_back(symbol_indexes[element]);
        });

        return arr_of_symbol_indexes;
    }

public:
    inline bool wordPattern(const std::string& pattern, const std::string& s) {
        std::vector<int> pattern_symbols = make_array_of_symbols_indexes(pattern.begin(), pattern.end());

        std::vector<std::string> s_words;
        std::stringstream ss(s);
        std::string word;
        while (ss >> word) {
            s_words.push_back(word);
        }

        std::vector<int> s_symbols = make_array_of_symbols_indexes(s_words.begin(), s_words.end());

        return pattern_symbols == s_symbols;
    }
};