/**
 *  First find the rotation (the position of the smallest element) and then find the target value in one of the parts.
 */
class Solution1 {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 1) return nums[0] == target ? 0 : -1;
        int rotate = find_rotate_index(nums);
        
        // if target is the smallest number
        if (nums[rotate] == target) {
            return rotate;
        }        
        
        // if not rotated
        if (rotate == 0) {
            return binary_search(nums, 0, n - 1, target);
        }
        // choose bs which side
        if (nums[0] > target)
            return binary_search(nums, rotate, n - 1, target);
        else // if (nums[0] <= target) 
            return binary_search(nums, 0, rotate - 1, target);
        
    }

    // Alternatively, we can compare nums[n-1] with nums[mid]
    int find_rotate_index(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        // check whether given nums is rotated
        if (nums[left] < nums[right])
            return 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // conditional check
            if (nums[mid] > nums[mid + 1])
                return mid + 1;
            else {
                if (nums[mid] < nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return 0;
    }
    
    int binary_search(vector<int>& nums, int start, int end, int target) {
        int l = start, r = end;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
};

/**
 * One-pass binary search
 */
class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < nums[right]) {
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            } else {
                if (nums[left] <= target && nums[mid] > target) right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }
};

/*
1- take the middle and compare with target, if matches return.
2- if middle is bigger than right side, it means left is sorted
2a- if [left] < target < [middle] then do recursion with left, middle - 1 (right)
2b- left side is sorted, but target not in here, search on right side middle + 1 (left), right
3- if middle is less than right side, it means right is sorted
3a- if [middle] < target < [right] then do recursion with middle + 1 (left), right
3b- right side is sorted, but target not in here, search on left side left, middle -1 (right)

*/
