#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B) {
        int n = A.size();
        vector<int> C(n), res(n);
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            int common = 0;
            if (A[i] == B[i]) {
                m[A[i]] += 2;
                common += 1;
            } else {
                m[A[i]]++;
                common += m[A[i]] > 1;
                m[B[i]]++;
                common += m[B[i]] > 1;
            }
            C[i] = common;
        }
        res[0] = C[0];
        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] + C[i];
        }
        return res;
    }
};