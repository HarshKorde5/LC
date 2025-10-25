/*
Hercy wants to save money for his first car. He puts money in the Leetcode bank every day.

He starts by putting in $1 on Monday, the first day. Every day from Tuesday to Sunday, he will put in $1 more than the day before. On every subsequent Monday, he will put in $1 more than the previous Monday.

Given n, return the total amount of money he will have in the Leetcode bank at the end of the nth day.
*/

#include<stdio.h>

/*
(total_weeks*(total_weeks-1)//2)*7 - Total incremental increase across total_weeks. Each new week starts $1 higher than the previous week, applied to all 7 days.

total_weeks*28 - Base weekly sum (1+2+...+7 = 28) repeated for all full total_weeks.

(total_days*(total_days+1)//2) - Sum of the first days days for the partial week (starting from Monday = 1).

total_weeks*total_days - Shift applied because the final partial week starts with total_weeks + $1.
*/

int totalMoney(int n)
{
    int total_weeks = n / 7;
    int extra_days = n % 7;
    int amount = ((total_weeks * (total_weeks - 1) / 2) * 7 + (total_weeks * 28)) + ((extra_days * (extra_days + 1) / 2) + (total_weeks * extra_days));
    return amount;
}

int main()
{
    int n = 20;
    printf("Total amount collected is : %d\n", totalMoney(n));
}