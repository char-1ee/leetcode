#include <bits/stdc++.h>
using namespace std;

class FooBar {
   private:
    int n;
    bool flag;
    std::mutex mtx;
    std::condition_variable cv;

   public:
    FooBar(int n) {
        this->flag = false;
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lk(mtx);
            cv.wait(lk, [this] { return !flag; });
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            flag = true;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lk(mtx);
            cv.wait(lk, [this] { return flag; });
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            flag = false;
            cv.notify_all();
        }
    }
};