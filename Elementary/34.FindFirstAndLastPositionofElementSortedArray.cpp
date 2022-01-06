class Solution {
    int search(vector<int>& a, int x) {
        int n = a.size();
        int left = 0, right = n - 1;
        int pos = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (a[mid] >= x) {
                pos = mid; 
                right = mid - 1;
            } else {    // a[mid] < x
                left = mid +1;
            }
        }
        return pos;
    }

public: 
    vector<int> searchRange(vector<int>& a, int x) {
        int first = search(a, x);
        int last = search(a, x + 1) - 1;
        if (first <= last)
            return {first, last};
        return {-1, -1};
    }
}