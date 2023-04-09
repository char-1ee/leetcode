#include <bits/stdc++.h>
using namespace std;

class LogSystem {
public:
    LogSystem() {
    }
    
    void put(int id, string timestamp) {
        m.insert({timestamp, id});
    }
    
    vector<int> retrieve(string start, string end, string granularity) {
        vector<int> res;
        convert(start, end, granularity);
        auto s = m.lower_bound(start);
        auto e = m.upper_bound(end);
        for (auto it = s; it != e; it++) {
            res.emplace_back(it->second);
        }
        return res;
    }

private:
    // multimap<string, int> m;
    map<string, int> m;

    void convert(string& s, string& e, string& g) {
        if (g == "Year") {
            s = s.substr(0, 4) + ":01:01:00:00:00";
            e = e.substr(0, 4) + ":12:31:23:59:59";
        }
        else if (g == "Month") {
            s = s.substr(0, 7) + ":01:00:00:00";
            e = e.substr(0, 7) + ":31:23:59:59";
        }
        else if (g == "Day") {
            s = s.substr(0, 10) + ":00:00:00";
            e = e.substr(0, 10) + ":23:59:59";
        }
        else if (g == "Hour") {
            s = s.substr(0, 13) + ":00:00";
            e = e.substr(0, 13) + ":59:59";
        }
        else if (g == "Minute") {
            s = s.substr(0, 16) + ":00";
            e = e.substr(0, 16) + ":59";
        }
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */