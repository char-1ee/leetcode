#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size(), MOD = 1e9 + 7;
        if (n < 3) return 0;

        sort(arr.begin(), arr.end());
        if (arr[0] * 3 > target || arr[n - 1] * 3 < target) return 0;

        long long res = 0;
        for (int i = 0; i < n - 2; i++) {
            int sum = target - arr[i];
            int left = i + 1, right = n - 1;

            while (left < right) {
                if (arr[left] + arr[right] == sum) {
                    if (arr[left] == arr[right]) {
                        res += (right - left + 1) * (right - left) / 2;
                        break;
                    }

                    int cnt1 = 1,
                        cnt2 = 1; // cnt of same numbers as arr[left] and arr[right] respectively
                    while (left + 1 < right && arr[left] == arr[left + 1]) {
                        cnt1++;
                        left++;
                    }
                    while (right - 1 > left && arr[right] == arr[right - 1]) {
                        cnt2++;
                        right--;
                    }

                    res += cnt1 * cnt2;
                    left++;
                    right--;
                } else if (arr[left] + arr[right] < sum) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return (int)(res % MOD);
    }
};