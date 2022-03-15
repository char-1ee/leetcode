class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int curr = -1, next = 0, steps = 0;
        for (int i = 0; next < n - 1; i++) {
            if (i > curr) {
                steps++;
                curr = next;
            }
            next = max(next, nums[i] + i);
        }
        return steps;
    }
};

//https://www.cnblogs.com/lichen782/p/leetcode_Jump_Game_II.html