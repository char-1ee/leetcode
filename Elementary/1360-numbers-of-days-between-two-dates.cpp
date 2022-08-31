#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int months[13] = {
        0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    
    // return 1 if is leap year, return 0 if not 
    int isLeap(int year) {
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
            return 1;
        return 0;
    }

    // Get days in a month fro certain year
    int getDaysAMonth(int year, int month) {
        if (month != 2) return months[month];
        return isLeap(year) + 28;
    }
    
    // Get how many days from 1971.1.1 to current date
    int getDays(string date) {
        int year, month, day;
        sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);

        int days = 0;

        // year count
        for (int i = 1971; i < year; i++) {
            days += 365 + isLeap(i);
        }

        // month count
        for (int i = 1; i < month; i++) {
            days += getDaysAMonth(year, i);
        }

        // day count
        days += day;
        
        return days;                
    }
    
    int daysBetweenDates(string date1, string date2) {
        return abs(getDays(date1) - getDays(date2));
    }
};