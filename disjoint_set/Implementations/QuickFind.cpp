class QuickFind {
public: 
    // O(N)
    QuickFind(int size): roots(size) {
        for (int i = 0; i < size; ++i)
            roots[i] = 1;
    }

    // O(1)
    int find(int x) {
        return roots[x];
    }

    // O(N)
    void unionSet(int x, int y) { // union x -> y
        int rootX = roots[x];
        int rootY = roots[y];
        if (rootX != rootY) {
            for (int i = 0; i < roots.size(); i++) {
                if (roots[i] == rootX)
                    roots[i] = rootY;
            }
        }
    }

    // O(1)
    bool connected(int i, int j) {
        return roots[i] == roots[j];
    }

private:
    vector<int> roots;
}