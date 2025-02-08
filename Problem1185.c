
/*
Given a date, return the corresponding day of the week for that date.

The input is given as three integers representing the day, month and year respectively.

Return the answer as one of the following values {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.

*/

#include<stdio.h>

char* dayOfTheWeek(int days, int month, int year) {
    char* findDay(int num) {
        char* arr[] = {"Thursday", "Friday",  "Saturday", "Sunday",
                       "Monday",   "Tuesday", "Wednesday"};
        return arr[num];
    }

    for (int i = 1971; i < year; i++) {
        if ((i % 4 == 0) && (i % 100 != 0 || i % 400 == 0))
            days += 366;
        else
            days += 365;
    }

    for (int i = 1; i < month; i++) {
        if (i == 2)
            if ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0))
                days += 29;
            else
                days += 28;
        else if (i == 4 || i == 6 || i == 9 || i == 11)
            days += 30;
        else
            days += 31;
    }
    return findDay(days % 7);
}

int main(){
    char *ptr = dayOfTheWeek(31,8,2019);
    printf("%s",ptr);
    return 0;
}