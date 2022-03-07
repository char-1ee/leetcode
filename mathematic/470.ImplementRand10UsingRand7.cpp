class Solution {
public:
    // reject sampling
    int rand10() {
        while (true) {
            int num = (rand7() - 1) * 7 + rand7();
            if (num <= 40) return num % 10 + 1;
        }
    }

    // reduce reject sampling probability
    int rand10() {
        while (true) {
            int a = rand7(), b = rand7();
            int num = (a-1) * 7 + b;
            if (num <= 40) return num % 10 + 1;
            a = num - 40, b = rand7();
            num = (a-1) * 7 + b;
            if (num <= 60) return num % 10 + 1;
            a = num - 60, b = rand7();
            num = (a - 1) * 7 + b;
            if (num <= 20) return num % 10 + 1;
        }
    }
};

/**
 * https://www.cnblogs.com/grandyang/p/9727206.html
 * - Reject random number by row-and-col into a table T(m, n)
 *   T = (randN() - 1) * M + randN() 
 * - Scaling rand7() with a constant to make distribution continuous uniform
 * 
 */