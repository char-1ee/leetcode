#include <bits/stdc++.h>
using namespace std;

// Divide and Conquer
// ave time O(nlogn), worst time O(n^2) when it is sorted.
// space O(n), recursion stack depth n
class Solution1 {
public:
    int largestRectangleArea(vector<int>& heights) {
        return helper(heights, 0, heights.size() - 1);
    }
    
    int helper(vector<int>& heights, int lo, int hi) {
        if (lo > hi) return 0;
        
        int minH = INT_MAX;
        int pivot;
        for (int i = lo; i <= hi; i++) {
            if (minH > heights[i]) {
                pivot = i;
                minH = heights[i];
            }
        }
        
        int pivotS = minH * (hi - lo + 1);
        int leftS = helper(heights, lo, pivot - 1);
        int rightS = helper(heights, pivot + 1, hi);
        
        return max(pivotS, max(leftS, rightS));
    }
};

// Brute force
// Time O(n^2) space O(1)
class Solution2 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        int area = 0;
        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; ++j) {
                int minH = INT_MAX;
                // for (int k = i; k <= j; k++) {
                //     minH = min(minH, heights[k]);
                // }
                minH = min(minH, heights[j]);
                area = max(area, minH * (j - i + 1));
            }
        }
        return area;
    }
};


// Monotonic stack
// Time O(n), space O(n)
class Solution3 {
public:
    int largestRectangleArea(vector<int> &height) {
        int res = 0;
        stack<int> st;
        height.push_back(0);
        for (int i = 0; i < height.size(); ++i) {
            if (st.empty() || height[st.top()] < height[i]) {
                st.push(i);
            } else {
                int cur = st.top(); st.pop();
                res = max(res, height[cur] * (st.empty() ? i : (i - st.top() - 1)));
                --i;
            }     
        }
        return res;
    }
};