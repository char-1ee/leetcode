class DisjointSet {
public:
    // O(N)
    DisjointSet (int size): roots(size), ranks(size) {
        for (int i = 0; i < size; ++i) {
            roots[i] = i;
            ranks[i] = i;
        }
    }

    // O(a(N)) -> average O(1)
    int find(int x) {
        if (x == roots[x])
            return x;
        return roots[x] = find(roots[x]);
    } 

    // O(a(N)) -> average O(1)
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

    // O(a(N)) -> average O(1)
    bool connected(int x, int y) {
        return find(x) == find(y);
    }

private:
    vector<int> roots;
    vector<int> ranks;
}