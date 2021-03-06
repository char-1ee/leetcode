package elementary;

import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {

        int n = nums.length;
        List<Integer> res = new ArrayList<>();
        int[] list = new int[n];

        for (int num : nums) {
            list[num - 1]++;
        }
        for (int i = 0; i < n; i++) {
            if (list[i] == 0)
                res.add(i + 1);
        }
        return res;
    }
}