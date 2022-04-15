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
    string longestCommonPrefix2(vector<string>& strs) {
        if (strs.empty()) return "";
        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != strs[0][i])
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }

    // divide and conquer
    string longestCommonPrefix3(vector<string>& strs) {
        if (strs.empty()) return "";
        return LCP(strs, 0, strs.size()-1);
    }
    
    string LCP(vector<string>& strs, int l, int r) {
        if (l == r) return strs[l];
        int mid = l + (r - l) / 2;
        string ls = LCP(strs, l, mid);
        string rs = LCP(strs, mid + 1, r);
        return findCommonPrefix(ls, rs);
    }
    
    string findCommonPrefix(string l, string r) {
        int i, n = min(l.size(), r.size());
        for (i = 0; i < n; i++) {
            if (l[i] != r[i])
                return l.substr(0, i);
        }
        return l.substr(0, n);
    }

    // binary search
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        unsigned int minLen = 201;
        for (string s : strs) {
            minLen = min(minLen, s.size()); // error: no matching function for call to 'min'
        }
        int left = 1; 
        int right = minLen;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isCommonPrefix(strs, mid))
                left = mid + 1;
            else right = mid - 1;
        }
        return strs[0].substr(0, (left + right) / 2);
    }
    
    bool isCommonPrefix(vector<string>& strs, int len) {
        string prefix = strs[0].substr(0, len);
        for (int i = 1; i < strs.size(); i++) {
            // !strs[i].startWith(prefix);
            if (strs[i].substr(0, len) != prefix)
                return false;
        }
        return true;
    }
};