import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.PriorityQueue;

class Solution {
    /** 
     * Hash Map + Max Heap
     * time O(Nlogk), space O(N+k)
     */
    public int[] topKFrequent1(int[] nums, int k) {
        if (nums.length == 1) return nums;
        
        int[] res = new int[k];
        HashMap<Integer, Integer> m = new HashMap<>();
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> m.get(a) - m.get(b)); // max heap
        
        for (int num : nums) {  // O(n)
            m.put(num, m.getOrDefault(num, 0) + 1);
        }
        for (int num : m.keySet()) {    // O(nlogk)
            pq.add(num); // log(k)
            if (pq.size() > k)
                pq.poll();
        }
        for (int i = 0; i < k; i++) {   // O(k)
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

        // buckets that indexing by frequency, every bucket contains elements with same frequency 
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
        for (int pos = buckets.length - 1; pos >= 0 && res.size() < k; pos--) { // notice that buckets is already sorted
            if (buckets[pos] == null) continue;
            res.addAll(buckets[pos]); 
        }
        return res;

        // a connflict that in case [1, 1, 2, 2, 3, 3] and k = 2, which return [1, 2, 3] length > k
        // so below is version that return int[] and resolve k's problem
        /*
        int[] result = new int[Math.min(freqMap.size(), k)]; // In case we want to return less than k elements, k could
                                                             // be greater than the number of distinct elements in nums.
        int resIdx = 0;
        for (int i = buckets.length - 1; i >= 0; --i) {
            if (buckets[i] == null)
                continue; 
            for (int currNum : buckets[i]) {
                result[resIdx++] = currNum;
                if (resIdx == result.length)
                    return result;
            }
        }
        return result;
        */
    }

    /** TODO: Quick select */

}