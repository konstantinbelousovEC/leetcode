// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long left = 0, right = n;

        while (left <= right) {
            long mid = (left + right) / 2;
            
            if ( isBadVersion(mid) && (mid == 1 || !isBadVersion(mid - 1)) ) {
                return mid;
            } else if (isBadVersion(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return n;
    }
};