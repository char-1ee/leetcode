/* lower_bound: Given a sorted ascending array, find the first num that >= target */
int find(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    return right;
}

/* Find the last num that < target */
int find(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    return right - 1;
}

/* A more comprehensive one */
int find(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    int ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] >= target) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}