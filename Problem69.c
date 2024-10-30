#include<stdio.h>

int mySqrt(int x) 
{
    if(x <= 1)
    {
        return x;
    }

    int low = 1,high = x/2;
    int ans;

    while(low<=high)
    {
        long int mid = (low+high)/2;
        long int square = mid*mid;

        if(square == x)
        {
            return mid;
        }
        if(square <= x)
        {
            low = mid + 1;
            ans = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{

    int ret = mySqrt(4);
    printf("%d\n",ret);
    
    return 0;
}