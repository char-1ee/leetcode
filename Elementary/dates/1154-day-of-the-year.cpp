#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int isLeap(int year) {
        if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
            return 1;
        return 0;
    }
    
    int getDaysInAMonth(int year, int month) {
        if (month != 2) return months[month];
        return isLeap(year) + 28;
    }
    
    int dayOfYear(string date) {
        // parse date
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        
        int res = 0;
        
        // get days in months
        for (int i = 1; i < month; i++) {
            res += getDaysInAMonth(year, i);
        }
        
        // get days
        res += day;
        
        return res;
    }
};