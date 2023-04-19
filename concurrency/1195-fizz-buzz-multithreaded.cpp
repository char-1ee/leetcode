#include <bits/stdc++.h>
#include <semaphore.h>
using namespace std;

// Semaphores
class FizzBuzz {
   private:
    int n;
    sem_t fizz_sem, buzz_sem, fizz_buzz_sem, num_sem;

   public:
    FizzBuzz(int n) {
        this->n = n;
        sem_init(&fizz_sem, 0, 0);
        sem_init(&buzz_sem, 0, 0);
        sem_init(&fizz_buzz_sem, 0, 0);
        sem_init(&num_sem, 0, 1);
    }

    ~FizzBuzz() {
        sem_destroy(&fizz_sem);
        sem_destroy(&buzz_sem);
        sem_destroy(&fizz_buzz_sem);
        sem_destroy(&num_sem);
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for (int i = 1; i <= n / 3 - n / 15; i++) {
            sem_wait(&fizz_sem);
            printFizz();
            sem_post(&num_sem);
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for (int i = 1; i <= n / 5 - n / 15; i++) {
            sem_wait(&buzz_sem);
            printBuzz();
            sem_post(&num_sem);
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        for (int i = 1; i <= n / 15; i++) {
            sem_wait(&fizz_buzz_sem);
            printFizzBuzz();
            sem_post(&num_sem);
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {
            sem_wait(&num_sem);  // -1
            if (i % 3 == 0 && i % 5 == 0)
                sem_post(&fizz_buzz_sem);
            else if (i % 3 == 0)
                sem_post(&fizz_sem);
            else if (i % 5 == 0)
                sem_post(&buzz_sem);
            else {
                printNumber(i);
                sem_post(&num_sem);  // +1
            }
        }
    }
};

// Condition variable
class FizzBuzz2 {
   private:
    int n;
    condition_variable cv;
    mutex mtx;
    atomic<int> cnt;

   public:
    FizzBuzz2(int n) {
        this->n = n;
        this->cnt = 0;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for (int i = 1; i <= n / 3 - n / 15; i++) {
            unique_lock<mutex> lk(mtx);
            cv.wait(lk, [this] { return cnt == 3; });
            printFizz();
            cnt = 0;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for (int i = 1; i <= n / 5 - n / 15; i++) {
            unique_lock<mutex> lk(mtx);
            cv.wait(lk, [this] { return cnt == 5; });
            printBuzz();
            cnt = 0;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        for (int i = 1; i <= n / 15; i++) {
            unique_lock<mutex> lk(mtx);
            cv.wait(lk, [this] { return cnt == 15; });
            printFizzBuzz();
            cnt = 0;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {
            unique_lock<mutex> lk(mtx);
            cv.wait(lk, [this] { return cnt == 0; });
            if (i % 3 == 0 && i % 5 == 0) {
                cnt = 15;
            } else if (i % 3 == 0) {
                cnt = 3;
            } else if (i % 5 == 0) {
                cnt = 5;
            } else {
                printNumber(i);
            }
            cv.notify_all();
        }
    }
};