package elementary.ksum;

import java.util.HashMap;

class TwoSum {
    
    private HashMap<Integer, Integer> map;
    
    public TwoSum() {
        this.map = new HashMap<>();
    }
    
    public void add(int number) {
        map.put(number, map.getOrDefault(number, 0) + 1);
    }
    
    public boolean find(int value) {
        for (int num : map.keySet()) {
            int sum = value - num;
            if ((num == sum && map.get(num) > 1) || (sum != num && map.containsKey(sum)))
                return true;
        }
        return false;
    }
}

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * boolean param_2 = obj.find(value);
 */
