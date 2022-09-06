// DFS recursion
class Solution1 {
public:
    vector<int> res;

    void dfs(int num, int n) {
        if (num > n) return;
        res.emplace_back(num);
        for (int i = 0; i <= 9; i++) {
            int next = num * 10 + i;
            if (next > n) break;
            dfs(next, n);
        }
    }

    vector<int> lexicalOrder(int n) {
        for (int i = 1; i <= 9; i++) {
            dfs(i, n);
        }
        return res;
    }
};

// DFS iteration, simulate dfs
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int num = 1; // current number
        for (int i = 1; i <= n; i++) {
            res.emplace_back(num);
            if (num * 10 <= n) { // dfs go deep
                num *= 10;
            } else if (num % 10 != 9 && num + 1 <= n) { // iterate horizontal
                num += 1;
            } else { // backtrack, go up (199 -> 2, 499 -> 5)
                while ((num / 10) % 10 == 9) {
                    num /= 10;
                }
                num = num / 10 + 1;
            }
        }
        return res;
    }
};
