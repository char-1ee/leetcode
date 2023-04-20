#include <bits/stdc++.h>
using namespace std;

// 1. Read-write lock using condition_variable_any
class BoundedBlockingQueue {
   public:
    BoundedBlockingQueue(int capacity) { this->cap = capacity; }

    void enqueue(int element) {
        // blocks are commonly used in RAII, to minimize lock for better perf
        {
            unique_lock<shared_mutex> lk(mtx);
            cv.wait(lk, [this] { return q.size() < cap; });
            q.push(element);
        }
        cv.notify_all();
    }

    int dequeue() {
        {
            unique_lock<shared_mutex> lk(mtx);
            cv.wait(lk, [this] { return q.size() > 0; });
            int elem = q.front();
            q.pop();
        }
        cv.notify_all();
        return elem;
    }

    int size() {
        shared_lock<shared_mutex> lk(mtx);
        return q.size();
    }

   private:
    int cap;
    queue<int> q;
    shared_mutex mtx;
    condition_variable_any cv;
};

// 2. Classic: 2 semaphores and 1 mutex
#include <semaphore.h>

class BoundedBlockingQueue2 {
   public:
    BoundedBlockingQueue2(int capacity) {
        sem_init(&slots, 0, capacity);
        sem_init(&elems, 0, 0);
    }

    ~BoundedBlockingQueue2() {
        sem_destroy(&slots);
        sem_destroy(&elems);
    }

    void enqueue(int element) {
        sem_wait(&slots);
        mtx.lock();
        q.push(element);
        mtx.unlock();
        sem_post(&elems);
    }

    int dequeue() {
        int res;
        sem_wait(&elems);
        mtx.lock();
        res = q.front();
        q.pop();
        mtx.unlock();
        sem_post(&slots);
        return res;
    }

    int size() { return q.size(); }

   private:
    sem_t slots, elems;
    mutex mtx;
    queue<int> q;
};