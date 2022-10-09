#include <bits/stdc++.h>
using namespace std;

class MyHashSet {
public:
    MyHashSet() {
        data.resize(1000, vector<bool>());
    }

    void add(int key) {
        int hashKey = key % 1000;
        if (data[hashKey].empty()) {
            data[hashKey].resize(1000, false);
        }
        data[hashKey][key / 1000] = true;
    }

    void remove(int key) {
        int hashKey = key % 1000;
        if (!data[hashKey].empty()) {
            data[hashKey][key / 1000] = false;
        }
    }

    bool contains(int key) {
        int hashKey = key % 1000;
        return !data[hashKey].empty() && data[hashKey][key / 1000] == true;
    }

private:
    vector<vector<bool>> data;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */