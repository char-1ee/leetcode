#include <bits/stdc++.h>
using namespace std;

class MovingAverage {
public:
    MovingAverage(int size) {
        this->window = size;
    }
    
    double next(int val) {
        if (window > size) {
            sum += val;
            size++;
            q.push(val);
            return sum*1.0 / size;
        } else {
            sum -= q.front();
            sum += val;
            q.pop();
            q.push(val);
            return sum*1.0 / window;
        }

    }
private:
    int size = 0; // current size
    int window; // window size
    queue<int> q;
    int sum = 0; // sum of elements in queue
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */