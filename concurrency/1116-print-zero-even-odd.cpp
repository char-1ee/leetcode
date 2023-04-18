#include <bits/stdc++.h>
#include <semaphore.h>
using namespace std;

class ZeroEvenOdd {
private:
    int n;
    sem_t zero_sem, odd_sem, even_sem;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        sem_init(&zero_sem, 0, 1);
        sem_init(&odd_sem, 0, 0);
        sem_init(&even_sem, 0, 0);
    }

    ~ZeroEvenOdd() {
        sem_destroy(&zero_sem);
        sem_destroy(&odd_sem);
        sem_destroy(&even_sem);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; i++) {
            sem_wait(&zero_sem);
            printNumber(0);
            if (i % 2)
                sem_post(&even_sem);
            else
                sem_post(&odd_sem);
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            sem_wait(&even_sem);
            printNumber(i);
            sem_post(&zero_sem);
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            sem_wait(&odd_sem);
            printNumber(i);
            sem_post(&zero_sem);
        }
    }
};