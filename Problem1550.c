//Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.

#include<stdio.h>
#include<bool.h>

bool threeConsecutiveOdds(int* arr, int arrSize)
{
    int i = 0,count = 0;
    while(i <= arrSize - 1)
    {
        if(count == 3)
            break;
            
        if(arr[i]%2 != 0)
        {
            count++;
        }
        else
        {
            count = 0;
        }
        i++;
    }

    if(count == 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    int arr[] = {1,1,1};

    bool bret = threeConsecutiveOdds(arr,3);
    
    return 0;
}