// ellegant solution with std::unordered_map;

class Solution {
public:
    inline int singleNumber(std::vector<int>& nums) {
        std::unordered_map<int, int> map_of_nums;
        map_of_nums.reserve((nums.size() / 3) + 1);

        std::for_each(nums.begin(), nums.end(), [&](int elem) mutable {
            map_of_nums[elem]++;
        });

        auto iterator = std::find_if(map_of_nums.begin(), map_of_nums.end(), [](const std::pair<int, int>& pair){
            return pair.second == 1;
        });

        return iterator->first;
    }

};


// bit manipulation

class Solution {
public:
    inline int singleNumber(vector<int>& nums) {
        int res = 0;
        for (char i = 0; i < 32; i++) {
            int sum = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (getBit(nums[j], i)) sum++;
            }
            if (sum % 3 != 0) res = setBit(res, i);
        }
        return res;
    }

private:
    inline bool getBit(int n, int pos) {
        return ( (n & (1 << pos)) != 0 );
    }

    inline int setBit(int n, int pos) {
        return ( (n | (1 << pos)) );
    }
};