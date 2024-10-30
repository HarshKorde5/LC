/*
At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

Note that you do not have any change in hand at first.

Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.
*/


#include<stdio.h>
#include<stdbool.h>

bool lemonadeChange(int* bills, int billsSize)
{
    int bill[3] = {0};
    bool flag = true;

    for(int i = 0;i < billsSize;i++)
    {
        if(bills[i] == 5)
        {
            bill[0]++;
        }
        else if(bills[i] == 10)
        {
            bill[1]++;
            if(bill[0] != 0)
            {
                bill[0]--;
            }
            else
            {
                flag = false;
            }
        }
        else if(bills[i] == 20)
        {
            bill[2]++;
            if(bill[0] != 0 && bill[1] != 0)
            {
                bill[0]--;
                bill[1]--;
            }
            else if(bill[0] >= 3)
            {
                bill[0] = bill[0] - 3;
            }
            else
            {
                flag = false;
            }
        }
    }
    return flag;
}

int main()
{
    int bills[] = {5,5,10,20};
    printf("%s\n",lemonadeChange(bills,4));

    return 0;
}