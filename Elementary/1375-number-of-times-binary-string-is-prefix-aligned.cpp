class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int cnt = 0;
        int right = 0; // keep position of the rightmost 1
        for (int i = 0; i < flips.size(); i++) {
            right = max(right, flips[i]);
            if (right == i + 1) // i+1 means there are i + 1 prefix bulbs lightened
                cnt++;
        }
        return cnt;
    }
};