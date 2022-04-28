class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        // Merge sort from the end.
        int i = m - 1, j = n - 1, k = n + m - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] <= nums2[j]) {
                nums1[k--] = nums2[j--];
            } else {
                nums1[k--] = nums1[i--];
            }
        }
        // ALERT: i or j probably >= 0 when the loop end.
        while (j >= 0)
            nums1[k--] = nums2[j--];

        // while (j >= 0){
        // nums1[k--] = (i >= 0 && nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
        // }
    }
}

/**
 * Two pitfalls：
 * 1. Sorting from end rather than from beginning (right to left);
 * 2. Three pointers rather than two: one more for return array.
 */