#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    MedianFinder() {}

    void addNum(int num) {
        int size = q1.size() + q2.size();
        if ((size & 1) == 0) { // even
            if (q1.size() > 0 && num < q1.top()) {
                q1.push(num);
                int t = q1.top();
                q1.pop();
                num = t;
            }
            q2.push(num);
            return;
        } else { // odd
            if (q2.size() > 0 && num > q2.top()) {
                q2.push(num);
                int t = q2.top();
                q2.pop();
                num = t;
            }
            q1.push(num);
            return;
        }
    }

    double findMedian() {
        int size = q1.size() + q2.size();
        double median = 0;
        if ((size & 1) == 0) {
            median = (q1.top() + q2.top()) / 2.0;
        } else {
            median = q2.top();
        }
        return median;
    }

private:
    priority_queue<int> q1; // max heap (downside)
    priority_queue<int, vector<int>, greater<int>> q2; // min heap (upside)
};

class MedianFinder2 {
public:
    void addNum(int num) {
        min.push(num);
        max.push(min.top());
        min.pop();

        if (min.size() < max.size()) {
            min.push(max.top());
            max.pop();
        }
    }

    double findMedian() {
        if (min.size() > max.size()) {
            return min.top() * 1.0;
        } else {
            return 0.5 * (min.top() + max.top());
        }
    }

private:
    priority_queue<int> min;
    priority_queue<int, vector<int>, greater<int>> max;
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */