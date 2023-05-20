#include <bits/stdc++.h>
using namespace std;

class Codec {
   public:
    // Encodes a list of strings to a single string.
    string encode(vector<string> &strs) {
        string res;
        for (auto &s : strs) {
            res += to_string(s.size()) + "/" + s;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        for (int i = 0; i < s.size();) {
            size_t pos = s.find("/");
            int len = stoi(s.substr(0, pos));
            s = s.substr(pos + 1);
            res.push_back(s.substr(0, len));
            s = s.substr(len);
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));