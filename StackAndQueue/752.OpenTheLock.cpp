class Solution {    
public:
    int openLock(vector<string>& deadends, string target) {    
        if (target == "0000") return 0;
        unordered_set<string> deadlock(deadends.begin(), deadends.end());
        if (deadlock.count("0000")) return -1;
        
        queue<string> q{{"0000"}};
        unordered_set<string> visited{{"0000"}};
        int cnt = 0;
        
        while (!q.empty()) {
            ++cnt;
            int len = q.size(); // CAUTION! size of q is changing
            for (int i = 0; i < len; ++i) {
                string t = q.front(); q.pop();
                for (int j = 0; j < t.size(); ++j) {
                    for (int k = -1; k <= 1; ++k) { // k is for +1/-1 on every digit
                        if (k == 0) continue;
                        string str = t;
                        str[j] = ((t[j] - '0') + 10 + k) % 10 + '0';
                        if (str == target) return cnt;
                        if (!visited.count(str) && !deadlock.count(str)) q.push(str);
                        visited.insert(str);
                    }
                }
            }
        }
        return -1;
    }
};