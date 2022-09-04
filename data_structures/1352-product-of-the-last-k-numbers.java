package data_structures;

import java.util.ArrayList;
import java.util.List;

class ProductOfNumbers {
    private List<Integer> list;

    public ProductOfNumbers() {
        this.list = new ArrayList<>();
        this.list.add(1);
    }
    
    public void add(int num) {
        if (num == 0) {
            list = new ArrayList<>();
            list.add(1);
        } else {
            int tmp = list.get(list.size() - 1) * num;
            list.add(tmp);
        }
    }
    
    public int getProduct(int k) {
        int n  = list.size();
        if (k < n)
            return list.get(n - 1) / list.get(n - k - 1);
        else 
            return 0;
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */