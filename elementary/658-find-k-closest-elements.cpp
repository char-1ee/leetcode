#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Sort with comparator
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (arr.size() == 1 || arr.size() == k) return arr;
        
        auto comp = [&](const int& a, const int& b) {
            return abs(a - x) < abs(b - x);
        };
        
        stable_sort(arr.begin(), arr.end(), comp);
        
        vector<int> res(arr.begin(), arr.begin() + k);
        sort(res.begin(), res.end());
        return res;
    }

    // Binary search with 2 pointers
    vector<int> findClosestElements2(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int right = lower_bound(arr.begin(), arr.end() - k, x) - arr.begin();
        int left = right - 1;

        while (k--) {
            if (right >= n || left >= 0 && (x - arr[left]) <= (arr[right] - x)) {
                left--;
            } else {
                right++;
            }
        }
        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};