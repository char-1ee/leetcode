package backtracking;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;

class Solution {
    /** Hashset + bool array to check visited: slow */
    public List<List<Integer>> permuteUnique(int[] nums) {
        Set<List<Integer>> s = new HashSet<>();
        List<Integer> track = new ArrayList<>();
        boolean[] visited = new boolean[nums.length];
        backtrack(nums, visited, track, s);
        List<List<Integer>> res = new ArrayList<>(s);
        return res;
    }

    private void backtrack(int[] nums, boolean[] visited, List<Integer> track, Set<List<Integer>> set) {
        if (nums.length == track.size()) {
            set.add(new ArrayList<>(track));
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (visited[i] == true)
                continue;
            visited[i] = true;
            track.add(nums[i]);
            backtrack(nums, visited, track, set);
            visited[i] = false;
            track.remove(track.size() - 1);
        }
    }

    /** hash map on nums: better */
    public List<List<Integer>> permuteUnique2(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        LinkedList<Integer> track = new LinkedList<>();
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        backtrack2(nums.length, track, res, map);
        return res;
    }

    private void backtrack2(int len, LinkedList<Integer> track, List<List<Integer>> res,
            HashMap<Integer, Integer> map) {
        if (track.size() == len) {
            res.add(new ArrayList<>(track));
            return;
        }
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int num = entry.getKey();
            int count = entry.getValue();
            if (count == 0)
                continue;

            track.add(num);
            map.put(num, count - 1);
            backtrack2(len, track, res, map);
            track.removeLast();
            map.put(num, count);
        }
    }

    /** Without hash set */
    public List<List<Integer>> permuteUnique3(int[] nums) {
        LinkedList<Integer> track = new LinkedList<>();
        List<List<Integer>> res = new ArrayList<>();
        boolean[] visited = new boolean[nums.length];
        Arrays.sort(nums);

        backtrack3(nums, visited, track, res);
        return res;
    }

    private void backtrack3(int[] nums, boolean[] visited, LinkedList<Integer> track, List<List<Integer>> res) {
        if (nums.length == track.size()) {
            res.add(new ArrayList<>(track));
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (visited[i] == true)
                continue;
            if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == true)
                continue;

            visited[i] = true;
            track.add(nums[i]);
            backtrack3(nums, visited, track, res);
            visited[i] = false;
            track.removeLast();
        }
    }
}