#include <bits/stdc++.h>
using namespace std;

// Condition variable (mutex + shared variable)
class Foo {
public:
    Foo() {
        cnt = 1;
    }

    void first(function<void()> printFirst) {
        std::unique_lock<std::mutex> lk(mtx);
                
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        cnt++;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lk(mtx);
        while (cnt != 2) {
            cv.wait(lk);
        }
        
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        cnt++;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lk(mtx);
        while (cnt != 3) {
            cv.wait(lk);
        }        
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

private:
    std::mutex mtx;
    std::condition_variable cv;
    std::atomic<int> cnt;
};

// Using just 2 mutex
class Foo2 {
public:
    Foo2() {
        m1.lock();
        m2.lock();
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        m1.unlock();
    }

    void second(function<void()> printSecond) {
        
        m1.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        m2.unlock();
        m1.unlock();
    }

    void third(function<void()> printThird) {
        m2.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        m2.unlock();
    }

private:
    std::mutex m1, m2;
};