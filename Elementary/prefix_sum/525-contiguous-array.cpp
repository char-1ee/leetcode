class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), res = 0, sum = 0;
        unordered_map<int, int> m{{0, -1}};
        for (int i = 0; i < n; i++) {
            sum += (nums[i] == 1) ? 1 : -1;
            if (m.count(sum)) {
                res = max(res, i - m[sum]);
            } else {
                m[sum] = i;
            }
        }
        return res;
    }
};