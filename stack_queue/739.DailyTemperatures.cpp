class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        // since we need to calculate intervals, 
        // this stack is used to store index nor integers in array
        stack<int> s;   

        // for convenience use access of aray index, we initialize
        // the result array with a length and all set to zero
        vector<int> ans(n, 0);

        for (int i = 0; i < n; ++i) {
            while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
                int t = s.top(); s.pop();
                ans[t] = i - t;
            }         
            s.push(i);
        }
        return ans;
    }
};

/**
 * Monotonic stacks 
 * 
 * Refer to https://leetcode.com/problems/daily-temperatures/solution/
 * Monotonic stacks are a good option when a problem involves 
 * comparing the size of numeric elements, with their order being relevant.
 * 
 */