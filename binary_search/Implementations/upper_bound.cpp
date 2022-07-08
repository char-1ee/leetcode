#include <bits/stdc++.h>

using namespace std;

// upper_bound: For a ascending array, find the first num that > target
int find_fisrt_num_larger_than_target(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }
    return right;
}

// Find the last num that <= target
int find_last_not_larger_than_target(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }
    return right - 1;
}

// About lower_bound and upper_bound
int main() {
    int gfg[] = {5, 6, 7, 7, 6, 5, 5, 6};
    vector<int> v(gfg, gfg + 8); // 5 6 7 7 6 5 5 6
    sort(v.begin(), v.end()); // 5 5 5 6 6 6 7 7

    vector<int>::iterator lower, upper;
    // lower_bound returns an iterator pointing to the first element in the range [first,last) which
    // has a value not less than ‘val’.
    lower = lower_bound(v.begin(), v.end(), 6); // index 3 (from 0)

    // upper_bound returns an iterator pointing to the first element in the range [first,last) which
    // has a value greater than ‘val’.
    upper = upper_bound(v.begin(), v.end(), 6); // index 6 (from 0)

    cout << "lower_bound for 6 at position " << (lower - v.begin() + 1) << '\n';
    cout << "upper_bound for 6 at position " << (upper - v.begin() + 1) << '\n';

    return 0;
}