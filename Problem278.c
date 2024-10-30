/*
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
*/
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

#include<stdio.h>
#include<stdbool.h>


bool isBadVersion(int n)
{
    return (n%2==0) ? true : false;
}

int firstBadVersion(int n)
{
    int high = n - 1;
    int low = 0;

    while(low <= high)
    {
        int mid = low+(high-low)/2;

        if(isBadVersion(mid))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}


int main()
{
    printf("%d\n",firstBadVersion(5));
    return 0;
}