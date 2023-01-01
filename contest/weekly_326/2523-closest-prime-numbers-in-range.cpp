#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> res(2, -1);
        vector<bool> prime(right + 1, true);
        prime[1] = false;

        for (int i = 2; i * i <= right; i++) {
            if (prime[i] == true) {
                for (int j = i * i; j <= right; j += i) {
                    prime[j] = false;
                }
            }
        }

        vector<int> primes;
        for (int i = left; i <= right; i++) {
            if (prime[i]) primes.push_back(i);
        }

        int n = primes.size();
        if (n < 2) return res;

        int minDist = primes[1] - primes[0];
        res[0] = primes[0];
        res[1] = primes[1];
        for (int i = 2; i < n; i++) {
            if (minDist > primes[i] - primes[i - 1]) {
                minDist = primes[i] - primes[i - 1];
                res[0] = primes[i - 1];
                res[1] = primes[i];
            }
        }
        return res;
    }
};