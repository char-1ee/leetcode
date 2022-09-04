#include <bits/stdc++.h>
using namespace std;

class ProductOfNumbers {
public:
    ProductOfNumbers() {}

    void add(int num) {
        if (num == 0) {
            nums = {1};
        } else {
            nums.emplace_back(nums.back() * num);
        }
    }

    int getProduct(int k) {
        if (k >= nums.size()) { // nums.size() always > num if there is no 0s.
            return 0;
        } else {
            return nums.back() / nums[nums.size() - k - 1];
        }
    }

private:
    vector<int> nums{1};
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */