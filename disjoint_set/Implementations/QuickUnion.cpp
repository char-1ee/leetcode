class QuickUnion {
public:
    // O(N)
    QuickUnion(int size): roots(size) {
        for (int i = 0; i < size; ++i) {
            roots[i] = 1;
        }
    }

    // O(N)
    int find(int x) {
        while (x != roots[x])
            x = roots[x];
        return x;
    }

    // O(N)
    void unionSet(int x, int y) { // union y -> x
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
            roots[rootY] = rootX;
    }

    // O(N)
    bool connected(int x, int y) {
        return find(x) == find(y);
    }

private:
    vector<int> roots;
};