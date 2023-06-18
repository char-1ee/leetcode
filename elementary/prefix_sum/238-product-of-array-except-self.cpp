class Solution {
public:
    // time: O(n), space: O(n)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // 1 suffix product array + 1 prefix product array
        vector<int> prefix(n, 1), suffix(n, 1);
        for (int i = 1, j = n - 2; i < n && j >= 0; ++i, --j) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
            suffix[j] = suffix[j + 1] * nums[j + 1];
        }
        // num = (product left of num) * (product right of num)
        for (int i = 0; i < n; i++) {
            nums[i] = prefix[i] * suffix[i];
        }
        return nums;
    }

    // time: O(n), space: O(1)
    vector<int> productExceptSelf2(vector<int>& nums) {
        int n = nums.size(), spice = 1;
        vector<int> res(n, 1); // not count in space consumed
        for (int i = 1; i < n; ++i) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        for (int j = n - 1; j >= 0; --j) {
            res[j] *= spice;
            spice *= nums[j];
        }
        return res;
    }
};