#include "../utils/utility.h"
using namespace std;

class CustomStack {
public:
    CustomStack(int maxSize) {
        this->size = 0;
        this->limit = maxSize;
    }

    void push(int x) {
        if (size < limit) {
            dq.push_back(x);
            size++;
        }
    }

    int pop() {
        if (size == 0) return -1;

        int res = dq.back();
        dq.pop_back();
        size--;
        return res;
    }

    void increment(int k, int val) {
        for (int i = 0; i < size; ++i) {
            int tmp = dq.front();
            dq.pop_front();
            if (i < k) tmp += val;
            dq.push_back(tmp);
        }
    }

private:
    deque<int> dq;
    int size;
    int limit;
};

class CustomStack2 {
public:
    CustomStack2(int maxSize) { limit = maxSize; }

    void push(int x) {
        if (s.size() < limit) {
            s.emplace_back(x);
            inc.emplace_back(0);
        }
    }

    int pop() {
        if (s.size() == 0) return -1;
        int lastIdx = s.size() - 1;

        if (lastIdx > 0) inc[lastIdx - 1] += inc[lastIdx];

        int res = s[lastIdx] + inc[lastIdx];
        s.pop_back();
        inc.pop_back();

        return res;
    }

    void increment(int k, int val) {
        int lastIdx = k;
        if (k > s.size()) {
            lastIdx = s.size() - 1;
        }
        
        if (lastIdx >= 0) inc[lastIdx] += val;
    }

private:
    int limit;
    vector<int> s; // stack
    vector<int> inc;
};