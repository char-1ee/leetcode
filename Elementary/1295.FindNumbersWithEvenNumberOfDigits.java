package Elementary;

class Solution {
    /** General solution */
    public int findNumbers1(int[] nums) {
        int cnt = 0, x;
        for (int num : nums) {
            x = 0;
            while (num > 0) {
                num = num / 10;
                x++;
            }
            if (x % 2 == 0)
                cnt++;
        }
        return cnt;
    }

    /** Mathematic solution */
    public int findNumbers2(int[] nums) {
        int cnt = 0;
        for (int num : nums) {
            if ((num > 9 && num < 100) || (num > 999 && num < 10000) || (num > 99999 && num < 1000000))
                cnt++;
        }
        return cnt;
    }
}
