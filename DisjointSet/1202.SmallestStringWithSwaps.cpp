class UnionFind {
public:
    UnionFind(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }

private:
    vector<int> root;
    vector<int> rank;
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<vector<int>> res(n);
        UnionFind uf(n);
        
        for (int k = 0; k < pairs.size(); ++k) {
            uf.unionSet(pairs[k][0], pairs[k][1]);
        }
        
        for (int i = 0; i < n; ++i) {
            res[uf.find(i)].push_back(i);
        }
        
        for (vector<int> &a : res) {
            string str = "";
            for (int index : a) str += s[index];
            sort(str.begin(), str.end());
            for (int j = 0; j < a.size(); ++j) {
                s[a[j]] = str[j];
            }
        }
        return s; 
    }
};