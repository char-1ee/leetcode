#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int minPrice = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else if (prices[i] - minPrice > maxProfit) {
                maxProfit = prices[i] - minPrice;
            }
        }
        return maxProfit;
    }
};

// Kadane's algorithm
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        
        int maxProfit = prices[1] - prices[0];
        int minPrice = prices[0]; // min price in front i-1 numbers in array
        
        for (int i = 2; i < prices.size(); i++) {
            if (prices[i - 1] < minPrice)
                minPrice = prices[i - 1];
            if (prices[i] - minPrice > maxProfit)
                maxProfit = prices[i] - minPrice;
        }
        return maxProfit < 0 ? 0 : maxProfit;
    }
};