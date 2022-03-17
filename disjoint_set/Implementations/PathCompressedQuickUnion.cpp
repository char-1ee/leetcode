class PathCompressedQuickUnion {
public:
    // O(N)
    PathCompressedQuickUnion(int size): roots(size) {
        for (int i = 0; i < size; ++i) {
            roots[i] = i;
        }
    }

    // worst O(logN)
    int find(int x) {
        if (x == roots[x])
            return x;
        return roots[x] = find(roots[x]);
    }

    // worst O(logN)
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            roots[rootX] = rootX;
        } 
    }

    // worst O(logN)
    bool connected(int x, int y) {
        return find(x) == find(y);
    }

private:
    vector<int> roots;
}