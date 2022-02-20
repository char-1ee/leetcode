class Solution {

    /** Brute force but TLE */
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;         
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            int sum = 0;
            for (int j = i; cnt < n; j++, cnt++) {
                sum = sum + gas[j % n] - cost[j % n];
                if (sum < 0) break;
            }
            if (cnt == n && sum >= 0) return i;
        }
        return -1;    
    }

    /** One pass */
    public int canCompleteCircuit2(int[] gas, int[] cost) {
        int n = gas.length;
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += gas[i] - cost[i];
        }
        if (total < 0) return -1;
        
        int sum = 0, start = 0;
        for (int i = 0; i < n; i++) {
            sum += gas[i] - cost[i];
            if (sum < 0) {
                start = i + 1;  // proof by contradiction
                sum = 0;
            }
        }
        return start;
    }
}