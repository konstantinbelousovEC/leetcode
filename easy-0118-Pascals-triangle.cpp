class Solution {
public:
    std::vector<std::vector<int>> generate1(int num_rows) {
        std::vector<std::vector<int>> result;
        result.reserve(num_rows);
        result.emplace_back(std::vector<int>{1});

        int current_vector_size = 2;
        while (num_rows > 1) {
            auto&& previous_vector = result.back();
            result.emplace_back(std::vector<int>{});
            auto&& current_vector = result.back();
            current_vector.reserve(current_vector_size);

            for (int i = 0; i < current_vector_size; i++) {
                if (i == 0) {
                    current_vector.push_back(1);
                } else if (i == current_vector_size - 1) {
                    current_vector.push_back(1);
                } else {
                    current_vector.push_back(previous_vector[i - 1] + previous_vector[i]);
                }
            }

            current_vector_size++;
            num_rows--;
        }

        return result;
    }

    std::vector<std::vector<int>> generate2(int num_rows) {
        if (num_rows == 1) return std::vector<std::vector<int>>{std::vector<int>{1}};

        std::vector<std::vector<int>> result;
        result.reserve(num_rows);

        for(int i = 0; i < num_rows; i++) {
            std::vector<int> row(i+1); 

            row[0] = 1;
            for(int j = 1; j < i; j++) {
                row[j] = result[i-1][j-1] + result[i-1][j];
            }
            row[i] = 1;

            result.emplace_back(row);
        }

        return result;
    }
};