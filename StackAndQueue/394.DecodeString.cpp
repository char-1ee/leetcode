class Solution {
public:
    string decodeString(string s) {
        stack<int> s_num;
        stack<string> s_str;
        string t = "";
        int cnt = 0; // every prefix number indicator
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                cnt = cnt * 10 + (s[i] - '0');
            } else if (s[i] == '[') {
                s_num.push(cnt);
                s_str.push(t);
                cnt = 0;
                t.clear();
            } else if (s[i] == ']') {
                int repeat = s_num.top(); s_num.pop();
                for (int j =0 ; j < repeat; ++j) {
                    s_str.top() += t;
                }
                t = s_str.top();
                s_str.pop();
            } else {
                t += s[i];
            }
        }
        return s_str.empty() ? t : s_str.top();
    }
};