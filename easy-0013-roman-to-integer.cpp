#include <string>

class Solution {
public:
    int romanToInt(std::string s);
private:
    int ArabicEquivalentToRoman(char c);
    int MakeArabicNumber(int *arr, int size);
};

int Solution::romanToInt(std::string s) {
    int size = static_cast<int>(s.size());
    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = ArabicEquivalentToRoman(s[i]);
    }
    return MakeArabicNumber(arr, size);
}

int Solution::ArabicEquivalentToRoman(char c) {
    switch (c) {
        case 'I':    return 1;
        case 'V':    return 5;
        case 'X':    return 10;
        case 'L':    return 50;
        case 'C':    return 100;
        case 'D':    return 500;
        case 'M':    return 1000;
        default:     return 0;
    }
}

int Solution::MakeArabicNumber(int *arr, int size) {
    int result = 0;
    int tmp = 0;
    for (int i = 0; i < size; i++) {
        if (i == size - 1) {
            if (i == 0) return arr[i];
            if (arr[i] > arr[i - 1]) {
                result = result + (arr[i] - tmp);
                tmp = 0;
            } else {
                result = result + arr[i];
            }
        } else if (arr[i] < arr[i + 1]) {
            tmp = arr[i];
        } else {
            result += (arr[i] - tmp);
            tmp = 0;
        }
    }
    return result;
}