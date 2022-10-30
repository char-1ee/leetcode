#include <bits/stdc++.h>
using namespace std;

// Check from right hand side.
// Time O(lognlogn), space O(1)
class Solution1 {
public:
    int sum(long long n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    long long makeIntegerBeautiful(long long n, int target) {
        long long n0 = n, base = 1;
        while (sum(n) > target) {
            n = n / 10 + 1;
            base *= 10;
        }
        return n * base - n0;
    }
};

// Same idea, but change long long into string to process
class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        string s = to_string(n);
        int sum = 0, len = s.length();
        for (int i = 0; i < len; i++) {
            sum += s[i] - '0';
        }
        if (sum <= target) return 0L;

        for (int i = len - 2; i >= 0; i--) {
            if (s[i] == '9') continue;

            // calculate sum of changed string
            sum = 0;
            for (int j = 0; j <= i; j++) {
                sum += s[j] - '0';
            }
            sum++;
            if (sum <= target) {
                string copy = s;
                for (int k = i + 1; k < len; k++) {
                    copy[k] = '0'; // change all after number into 0
                }
                copy[i]++;
                return stoll(copy) - n;
            }
        }
        return stoll('1' + string(len, '0')) - n;
    }
};