class Solution {
public:
    /** Iterative */
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> q{{0}};
        unordered_set<int> visited{{0}};
        while (!q.empty()) {
            int room = q.front(); q.pop();
            for (int key : rooms[room]) {
                if (visited.count(key)) continue;
                visited.insert(key);
                if (visited.size() == n) break;
                q.push(key);
            }
        }
        return visited.size() == rooms.size();
    }

    /** Recursive */
     void dfs(vector<vector<int>>& rooms, int index, unordered_set<int>& visited) {
        visited.insert(index);
        for (int k : rooms[index]) {
            if (!visited.count(k)) dfs(rooms, k, visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        dfs(rooms, 0, visited);
        return rooms.size() == visited.size();
    }
};