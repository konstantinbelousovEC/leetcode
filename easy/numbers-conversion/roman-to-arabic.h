#pragma once
#include <string>

class Solution {
public:
    int romanToInt(std::string s);
private:
    int ArabicEquivalentToRoman(char c);
    int MakeArabicNumber(int *arr, int size);
};
