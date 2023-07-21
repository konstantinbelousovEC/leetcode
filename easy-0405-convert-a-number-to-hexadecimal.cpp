class Solution {
private:
    constexpr static const std::array<char, 16> hex_symbols = {
        '0', '1', '2', '3',
        '4', '5', '6', '7',
        '8', '9', 'a', 'b',
        'c', 'd', 'e', 'f'
    };

    template<typename T>
    std::string write_bits(T num) {
        std::string res;
        while (num) {
            res += hex_symbols[num % 16];
            num >>= 4;
        }
        return res;
    }

public:
    inline std::string toHex(int num) {
        if (num == 0) return "0"s;

        std::string res;

        if (num > 0) {
            res = write_bits(num);
        } else {
            unsigned int u_num = num;
            res = write_bits(u_num);
        }

        std::reverse(res.begin(), res.end());

        return res;
    }

    inline std::string toHex2(int num) {
        std::stringstream ss;
        ss << hex << num;
        return ss.str();
    }
};