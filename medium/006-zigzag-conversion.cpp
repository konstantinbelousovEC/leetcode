#include <string>
#include <vector>

class Solution {
public:
    inline static std::string convert(const std::string& s, int num_rows) {
        if (num_rows == 1) return s;

        int str_size = s.size();
        int sections = ceil(str_size / (2 * num_rows - 2.0));
        int num_cols = sections * (num_rows - 1);

        std::vector<std::vector<char>> matrix(num_rows, std::vector<char>(num_cols, ' '));

        int current_row = 0, current_col = 0;
        int current_str_index = 0;

        while (current_str_index < str_size) {
            while (current_row < num_rows && current_str_index < str_size) {
                matrix[current_row][current_col] = s[current_str_index];
                current_row++;
                current_str_index++;
            }

            current_row -= 2;
            current_col++;

            while (current_row > 0 && current_col < num_cols && current_str_index < str_size) {
                matrix[current_row][current_col] = s[current_str_index];
                current_row--;
                current_col++;
                current_str_index++;
            }
        }

        std::string answer;
        for (auto& row: matrix) {
            for (auto& character: row) {
                if (character != ' ') {
                    answer += character;
                }
            }
        }

        return answer;
    }

    inline static std::string convert2(const std::string& s, int num_rows) {
        if (num_rows == 1) return s;

        std::string answer;
        int str_size = s.size();
        int chars_in_section = 2 * (num_rows - 1);

        for (int current_row = 0; current_row < num_rows; current_row++) {
            int index = current_row;

            while (index < str_size) {
                answer.push_back(s[index]);

                if (current_row != 0 && current_row != num_rows - 1) {
                    int chars_between_indexes = chars_in_section - (2 * current_row);
                    int second_index = index + chars_between_indexes;

                    if (second_index < str_size) answer.push_back(s[second_index]);
                }

                index += chars_in_section;
            }
        }

        return answer;
    }
};

int main() {
    Solution solution;

    assert(solution.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
    assert(solution.convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");

    assert(solution.convert2("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
    assert(solution.convert2("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
}