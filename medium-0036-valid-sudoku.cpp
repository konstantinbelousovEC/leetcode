// long solution, but 65% faster and 45% more effective by memory usage

class Solution {
private:

    static constexpr int SIZE = 9;

    inline bool checkRow(vector<char>& row) {
        std::set<char> digits;
        for (int i = 0; i < SIZE; i++) {
            if (row[i] != '.') {
                if (digits.count(row[i])) return false;
                digits.insert(row[i]);
            }
        }
        return true;
    }

    inline bool checkColumn(vector<vector<char>>& board, int j) {
        std::set<char> digits;
        for (int i = 0; i < SIZE; i++) {
            if (board[i][j] != '.') {
                if (digits.count(board[i][j])) return false;
                digits.insert(board[i][j]);
            }
        }
        return true;
    }

    inline bool checkBox(vector<vector<char>>& board, int i, int j) {
        std::set<char> digits;
        for (int a = i; a < i + 3; a++) {
            for(int b = j; b < j + 3; b++)
            if (board[a][b] != '.') {
                if (digits.count(board[a][b])) return false;
                digits.insert(board[a][b]);
            }
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for (auto&& row : board) {
            if (!checkRow(row)) return false;
        }
        for (int j = 0; j < SIZE; j++) {
            if (!checkColumn(board, j)) return false;
        }
        for (int i = 0; i < SIZE; i += 3) {
            for (int j = 0; j < SIZE; j += 3) {
                if (!checkBox(board, i, j)) return false;
            }
        }
        return true;
    }
};