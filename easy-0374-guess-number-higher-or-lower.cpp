/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

 // Binary Search | interactive

class Solution {
public:
    int guessNumber(int n) const noexcept {
        int l = 1, r = n;
        
        while (l <= n) {
            int m = l + (r - l) / 2;
            int g = guess(m);
            if (g == 0) return m;
            if (g == 1) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return 1;
    }
};

