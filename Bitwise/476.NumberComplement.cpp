class Solution {
public:
    int numComplement(int num) {

        // avoid stack overflow by unsigned int 
        unsigned mask = ~0;

        // find the highest 1 in num
        while (mask & num) mask <<= 1;

        return ~mask & ~num;
    }
};