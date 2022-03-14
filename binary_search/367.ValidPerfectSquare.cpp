class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2) return true;
        int left = 2, right = num / 2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long n = (long)mid * mid;
            if (n == num) return true;
            else if (n < num) left = mid + 1;
            else right = mid - 1;
        
        }
        return false;
    }
};