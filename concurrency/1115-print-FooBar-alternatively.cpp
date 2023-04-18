#include <bits/stdc++.h>
using namespace std;

// Condition variable + mutex
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

// Semaphore
#include <semaphore.h>

class FooBar2 {
   private:
    int n;
    sem_t sem1;  // 1
    sem_t sem2;  // 0

   public:
    FooBar2(int n) {
        this->n = n;
        sem_init(&sem1, 0, 1);
        sem_init(&sem2, 0, 0);
    }

    ~FooBar2() {
        sem_destroy(&sem1);
        sem_destroy(&sem2);
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            sem_wait(&sem1);
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            sem_post(&sem2);
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            sem_wait(&sem2);
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            sem_post(&sem1);
        }
    }
};