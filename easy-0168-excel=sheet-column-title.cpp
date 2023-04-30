class Solution {
public:
    string convertToTitle(int columnNumber) {
        std::string result;
        int remain;
        while (columnNumber > 0) {
            columnNumber--;
            remain = columnNumber % 26;
            char letter = 'A' + remain;
            result.insert(result.begin(), letter);
            columnNumber = columnNumber / 26;
        }
        return result;
    }
};