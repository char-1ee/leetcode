#include <bits/stdc++.h>
using namespace std;

class H2O {
private:
    mutex mtx;
    condition_variable cv;
    atomic<int> h; // count of H
public:
    H2O() {
        this->h = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lk(mtx);
        cv.wait(lk, [this] {
            return h < 2;
        });
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        h++;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lk(mtx);
        cv.wait(lk, [this] {
            return h >= 2;
        });
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        h -= 2;
        cv.notify_all();
    }
};