package hash_table;

import java.util.*;

class RandomizedCollection {

    private HashMap<Integer, HashSet<Integer>> map;
    private List<Integer> list;
    private Random rand;

    public RandomizedCollection() {
        this.map = new HashMap<>();
        this.list = new ArrayList<>();
        this.rand = new Random();
    }

    public boolean insert(int val) {
        boolean present = map.containsKey(val);
        if (!present) {
            map.put(val, new HashSet<>());
        }
        map.get(val).add(list.size());
        list.add(val);
        return !present;
    }

    public boolean remove(int val) {
        if (!map.containsKey(val))
            return false;

        HashSet<Integer> set = map.get(val);
        int idx = set.iterator().next();
        if (set.size() == 1) {
            map.remove(val);
        } else {
            set.remove(idx);
        }

        if (list.size() - 1 != idx) {
            int num = list.get(list.size() - 1);
            HashSet<Integer> set2 = map.get(num);
            set2.add(idx);
            set2.remove(list.size() - 1);
            list.set(idx, num);
        }
        list.remove(list.size() - 1);
        return true;
    }

    public int getRandom() {
        return list.get(rand.nextInt(list.size()));
    }
}

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */