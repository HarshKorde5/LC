/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API int guess(int num), which returns three possible results:

-1: Your guess is higher than the number I picked (i.e. num > pick).
1: Your guess is lower than the number I picked (i.e. num < pick).
0: your guess is equal to the number I picked (i.e. num == pick).
Return the number that I picked.
*/

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

#include<stdio.h>

int guess(int num)
{
    int pick = 5;

    if(num == pick)
    {
        return 0;
    }
    else if(num < pick)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int guessNumber(int n)
{
	int high = n,low = 1,mid = 0,i = 0;
    while(low <= high)
    {
        mid = low + (high-low)/2;
        i = guess(mid);

        if(i == 0)
        {
            return mid;
        }
        else if(i == -1)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;

        }
    }
    return mid;
}

int main()
{
    printf("%d\n",guessNumber(10));
    return 0;
}