package sorting;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Random;

class Solution {
    /**
     * Hash Map + Min Heap
     * time O(Nlogk), space O(N+k)
     */
    public int[] topKFrequent1(int[] nums, int k) {
        if (nums.length == 1)
            return nums;

        int[] res = new int[k];
        HashMap<Integer, Integer> m = new HashMap<>();
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> m.get(a) - m.get(b)); // min heap

        for (int num : nums) { // O(n)
            m.put(num, m.getOrDefault(num, 0) + 1);
        }
        for (int num : m.keySet()) { // O(nlogk)
            pq.add(num); // log(k)
            if (pq.size() > k)
                pq.poll();
        }
        for (int i = 0; i < k; i++) { // O(k)
            res[i] = pq.poll();
        }
        return res;
    }

    /**
     * Bucket sort
     * time O(n), space O(n)
     * https://leetcode.com/problems/top-k-frequent-elements/discuss/81602/Java-O(n)-Solution-Bucket-Sort
     */
    public List<Integer> topKElement2(int[] nums, int k) {

        // add values and their frequency
        HashMap<Integer, Integer> m = new HashMap<>();
        for (int num : nums) {
            m.put(num, m.getOrDefault(num, 0) + 1);
        }

        // buckets that indexing by frequency, every bucket contains elements with same
        // frequency
        @SuppressWarnings("unchecked")
        List<Integer>[] buckets = new ArrayList[nums.length + 1]; // length+1 in case e.g. [1, 1, 1, 1, 1]
        for (int key : m.keySet()) {
            int frequency = m.get(key);
            if (buckets[frequency] != null) {
                buckets[frequency] = new ArrayList<>();
            }
            buckets[frequency].add(key);
        }

        // retrieve the top k frequency element in nums from buckets
        List<Integer> res = new ArrayList<>();
        for (int pos = buckets.length - 1; k > 0; pos--) { // notice that buckets is already sorted
            if (buckets[pos] == null)
                continue;
            // res.addAll(buckets[pos]);
            for (int num : buckets[pos]) {
                res.add(num);
                k--;
            }
        }
        return res;

        // a connflict that in case [1, 1, 2, 2, 3, 3] and k = 2, which return [1, 2, 3]
        // length > k
        // so below is version that return int[] and resolve k's problem
        /*
         * int[] result = new int[Math.min(freqMap.size(), k)]; // In case we want to
         * return less than k elements, k could
         * // be greater than the number of distinct elements in nums.
         * int resIdx = 0;
         * for (int i = buckets.length - 1; i >= 0; --i) {
         * if (buckets[i] == null)
         * continue;
         * for (int currNum : buckets[i]) {
         * result[resIdx++] = currNum;
         * if (resIdx == result.length)
         * return result;
         * }
         * }
         * return result;
         */
    }
}

class QuickSelect {

    private int[] unique;
    private Map<Integer, Integer> count;

    /**
     * Lomuto partition:
     * https://en.wikipedia.org/wiki/Quicksort#Lomuto_partition_scheme
     */
    public int partition(int left, int right, int pivot_index) {
        int pivot_frequency = count.get(unique[pivot_index]);
        // 1. move pivot to end
        swap(pivot_index, right);
        int store_index = left;

        // 2. move all less frequent elements to the left
        for (int i = left; i <= right; i++) {
            if (count.get(unique[i]) < pivot_frequency) {
                swap(store_index, i);
                store_index++;
            }
        }

        // 3. move pivot to its final place
        swap(store_index, right);

        return store_index;
    }

    /**
     * Sort a list within left..right till kth less frequent element takes its
     * place.
     */
    public void quickselect(int left, int right, int k_smallest) {

        // base case: the list contains only one element
        if (left >= right)
            return;

        // select a random pivot_index
        Random rand = new Random();
        int pivot_index = left + rand.nextInt(right - left);

        // find the pivot position in a sorted list
        pivot_index = partition(left, right, pivot_index);

        // if the pivot is in its final sorted position
        if (k_smallest == pivot_index) {
            return;
        } else if (k_smallest < pivot_index) {
            quickselect(left, pivot_index - 1, k_smallest);
        } else {
            quickselect(pivot_index + 1, right, k_smallest);
        }
    }

    public int[] topKFrequent(int[] nums, int k) {
        count = new HashMap<>();
        for (int num : nums) {
            count.put(num, count.getOrDefault(num, 0) + 1);
        }

        int n = count.size();
        unique = new int[count.size()];
        int i = 0;
        for (int num : count.keySet()) {
            unique[i] = num;
            i++;
        }

        // kth top frequent element is (n - k)th less frequent.
        // Do a partial sort: from less frequent to the most frequent, till
        // (n - k)th less frequent element takes its place (n - k) in a sorted array.
        // All element on the left are less frequent.
        // All the elements on the right are more frequent.
        quickselect(0, n - 1, n - k);

        // Return top k frequent elements
        return Arrays.copyOfRange(unique, n - k, n);
    }

    public void swap(int a, int b) {
        int tmp = unique[a];
        unique[a] = unique[b];
        unique[b] = tmp;
    }
}