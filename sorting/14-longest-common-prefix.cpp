class Solution {
public:
    // sorting: then less common strings are seperated to the start and the end of array
    // Time: O(nlogn)
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        sort(strs.begin(), strs.end());
        int i, n = min(strs[0].size(), strs[strs.size() - 1].size());
        for (i = 0; i < n; i++) {
            if (strs[0][i] != strs[strs.size() - 1][i])
                break;
        }
        return strs[0].substr(0, i);
    }
    
    // Vertical scanning
    // Time: O(S) where S is the sum of all characters in all strings. 
    // Worst: S=n*m where there are n strings with equal length m,
    // Best: S=n*minLen where minlen is the length of the shortest string in the array.
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != strs[0][i])
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};