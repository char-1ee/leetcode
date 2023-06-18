class Solution {
public:
    // brute force with prefix sum
    // time: O(n^2), space: O(n)
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        vector<int> prefix = nums;
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }
        for (int i = 0; i < n; i++) {
            if (prefix[i] == k) ++res;
            for (int j = i - 1; j >= 0; j--) {
                if (prefix[i] - prefix[j] == k)
                    ++res;
            }
        }
        return res;
    }

    // hashmap + prefix sum, sum - k stored in map
    // time: o(n), space: O(n)
    int subarraySum(vector<int>& nums, int k) {
            int res = 0, sum = 0, n = nums.size();
            unordered_map<int, int> map {{0, 1}};
            for (int i = 0; i < n; i++) {
                sum += nums[i];
                res += map[sum - k];
                map[sum]++;
            }
            return res;
        }

};