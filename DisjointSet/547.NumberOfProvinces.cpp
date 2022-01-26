class Solution {
private:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i) {
        visited[i] = true; // visited to true is also a part of recursion, thus cannot put in main function
        for (int j = 0; j < visited.size(); j++) {
            if (i != j && isConnected[i][j] && !visited[j])
                dfs(isConnected, visited, j);
        }
    }
   
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0; // number of provinces
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            dfs(isConnected, visited, i);
            count++;
        }
        return count;
    }
};

/**
 * Q: What is the difference with Number of Islands?
 * 
 * A: This question is symmetric although a 2D grid is given.
 *    So, by the symmetric feature, we can simplify 2D space into linear space. 
 */