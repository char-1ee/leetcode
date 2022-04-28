package hash_table;

import java.util.*;

/**
 * Insert and Delete both have O(1) average time complexity, and O(N) in the
 * worst-case scenario when the operation exceeds the capacity of currently
 * allocated array/hashmap and invokes space reallocation.
 */
class RandomizedSet {

    private HashMap<Integer, Integer> map;
    private List<Integer> list;
    private Random rand = new Random();

    public RandomizedSet() {
        this.map = new HashMap<>();
        this.list = new ArrayList<>();
    }

    /** O(1) on average */
    public boolean insert(int val) {
        if (map.containsKey(val))
            return false;
        map.put(val, list.size());
        list.add(val);
        return true;
    }

    /** O(1) on average */
    public boolean remove(int val) {
        if (!map.containsKey(val))
            return false;
        int lastElement = list.get(list.size() - 1);
        int currIdx = map.get(val);

        map.put(lastElement, currIdx);
        list.set(currIdx, lastElement);

        list.remove(list.size() - 1);
        map.remove(val);
        return true;
    }

    /** O(1) */
    public int getRandom() {
        return list.get(rand.nextInt(list.size()));
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
