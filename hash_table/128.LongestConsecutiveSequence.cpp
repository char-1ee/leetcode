class Solution {
public:

    /** Sorting: O(nlogn) */
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() < 1) return 0;
        
        int longest = -1;
        int size = nums.size();
        int cnt = 1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < size; ++i) {
            if (nums[i-1] != nums[i]){
                if (nums[i - 1] + 1 == nums[i]){
                    ++cnt;
                } else {
                    longest = max(cnt, longest);
                    cnt = 1;
                }
            }
        }
        return max(longest, cnt);
    }

    /** Hash set: O(n) */
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_set<int> set;
        int longest = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            set.insert(nums[i]); // remove duplicates
        }
        
        for (int j = 0; j < nums.size(); ++j) 
        {
            if (set.count(nums[j] - 1)) continue;
            int cnt = 1;
            int curr = nums[j];
            while (set.count(curr + 1)) {
                ++cnt;
                ++curr;
            }
            longest = max(cnt, longest);
        }
        return longest;
    }
};