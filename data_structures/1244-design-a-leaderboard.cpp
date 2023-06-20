class Leaderboard {
private:
    unordered_map<int, int> m;
    set<pair<int, int>> st;
    
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        st.erase({m[playerId], playerId});
        m[playerId] += score;
        st.insert({m[playerId], playerId});
    }
    
    int top(int K) {
        int res = 0;
        int i = 0;
        for (auto it = st.rbegin(); it != st.rend() && i < K; it++, i++) {
            res += (it->first);
        }
        return res;
    }
    
    void reset(int playerId) {
        st.erase({m[playerId], playerId});
        m[playerclId] = 0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */