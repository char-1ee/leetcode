package disjoint_set;

class Solution {
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        if (n < 2) return 1;
        UF set = new UF(n);
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                if (isConnected[i][j] == 1 ) {
                    set.union(i, j);
                }
            }
        }
        return set.count();
    }
    
    class UF {
        private int cnt;
        private int[] roots;
        private int[] ranks;
        
        public UF(int size) {
            roots = new int[size];
            ranks = new int[size];
            cnt = size;
            for (int i = 0; i < size; i++) {
                ranks[i] = i;
                roots[i] = i;
            }
        }
        
        public int find(int x) {
            while (x != roots[x]) {
                roots[x] = roots[roots[x]];
                x = roots[x];
            }
            return x;
        }
        
        public void union(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                cnt--;
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
        
        public boolean check(int x, int y) {
            return find(x) == find(y);
        }
        
        public int count() {
            return cnt;
        }
    }
}