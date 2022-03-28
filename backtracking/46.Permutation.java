

import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> track = new ArrayList<>();
        backtrack(nums, track, res);
        return res;
    }
    
    private void backtrack(int[] A, List<Integer> track, List<List<Integer>> res) {
        if (track.size() == A.length) {
            res.add(new ArrayList<>(track));
            return;
        }
        for (int i = 0; i < A.length; i++) {
            if (track.contains(A[i]))
                continue;
            
            track.add(A[i]);
            backtrack(A, track, res);
            track.remove(track.size() - 1);
        }
    }
}