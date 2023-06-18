class Solution {
    /** Sorting: O(nlogn), O(1) */
    public boolean canAttendMeetings(int[][] intervals) {
        int n = intervals.length;
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < intervals[i - 1][1])
                return false;
        }
        return true;
    }

    /** brute force: O(n^2), O(1) */
    public boolean canAttendMeetings2(int[][] intervals) {
        int n = intervals.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int[] x = intervals[i], y = intervals[j];
                if (Math.max(x[0], y[0]) < Math.min(x[1], y[1]))
                    return false;
            }
        }
        return true;
    }
}