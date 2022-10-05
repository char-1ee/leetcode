#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /** Floyd's cycle finding algorithm */
    bool isHappy(int n) {
        int slow = n;
        int fast = next(n);
        while (true) {
            slow = next(slow);
            fast = next(next(fast));
            if (fast == 1 || fast == slow) break;
        }
        return fast == 1;
    }

    int next(int n) {
        int sum = 0;
        while (n > 0) {
            int m = n % 10;
            sum += m * m;
            n /= 10;
        }
        return sum;
    }

    // hashset 1
    bool isHappy2(int n) {
        unordered_set<int> st;
        while (n != 1) {
            int sum = 0;
            while (n) {
                int m = n % 10;
                n = n / 10;
                sum += m * m;
            }
            n = sum;
            if (st.count(n)) break;
            st.insert(n);
        }
        return n == 1;
    }

    // hashset 2, time O(logn), space O(logn)
    bool isHappy3(int n) {
        unordered_set<int> set;
        while (true) {
            int num = 0;
            while (n > 0) {
                int digit = n % 10;
                num += digit * digit;
                n /= 10;
            }
            n = num;
            if (n == 1) return true;
            if (set.count(n) > 0) {
                return false;
            } else {
                set.insert(n);
            }
        }
    }
};