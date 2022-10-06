class WeightedQuickUnion {
public:
    // O(N)
    WeightedQuickUnion(int size): roots(size), ranks(size) {
        for (int i = 0; i < size; ++i) {
            roots[i] = i;
            ranks[i] = 1;
        }
    }


    // worst O(logN)
    int find(int x) {
        while (x != roots[x])
            x = roots[x];
        return x;
    }

    // worst O(logN)
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (ranks[rootX] > ranks[rootY]) {
                roots[rootY] = rootX;
            } else if (ranks[rootX] < ranks[rootY]) {
                roots[rootX] = rootY;
            } else {
                roots[rootY] = rootX;
                ranks[rootX] += 1;
            }
        }
    }

    // worst O(logN)
    bool connected(int x, int y) {
        return find(x) == find(y);
    }

private: 
    vector<int> roots;
    vector<int> ranks;
};