class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() < 2) return stoi(tokens[0]);
        stack<int> s;
        for (string t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int x = s.top(); s.pop();
                int y = s.top(); s.pop();
                if (t == "+") s.push(x + y);
                if (t == "-") s.push(y - x);
                if (t == "*") s.push(x * y);
                if (t == "/") s.push(y / x);
            } else {
                s.push(stoi(t));
            }
        }
        return s.top();
    }
};