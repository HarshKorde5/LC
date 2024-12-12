//gcc Problem2558.c -o myexe -lm

/*
You are given an integer array gifts denoting the number of gifts in various piles. Every second, you do the following:

Choose the pile with the maximum number of gifts.
If there is more than one pile with the maximum number of gifts, choose any.
Leave behind the floor of the square root of the number of gifts in the pile. Take the rest of the gifts.
Return the number of gifts remaining after k seconds.
*/


#include<stdio.h>
#include<math.h>

//////////////////////////////////////////////////////////
//Brute force approach
//////////////////////////////////////////////////////////
int findMaxIdx(int* gifts,int giftsSize)
{
    int maxIdx = 0;

    for(int i = 1;i < giftsSize;i++)
    {
        if(gifts[i] > gifts[maxIdx])
        {
            maxIdx = i;
        }
    }

    return maxIdx;
}

long long pickGifts1(int* gifts, int giftsSize, int k) 
{
    long long sum = 0;

    for(int i = 1;i <= k;i++)
    {
        int maxIdx = findMaxIdx(gifts,giftsSize);

        long long sqr = floor(sqrt(gifts[maxIdx]));

        gifts[maxIdx] = sqr;
    }

    for(int i = 0;i < giftsSize;i++)
    {
        sum += gifts[i];
    }

    return sum;
}

/////////////////////////////////////////////////////////
//Heap approach
/////////////////////////////////////////////////////////

void heapify_down(int *heap, int len, int idx) 
{
    while (1) 
    {
        int l = (idx << 1) + 1;
        int r = l + 1;
        int new = idx;
        if (l < len && heap[l] > heap[new])
        {
            new = l;
        }
        if (r < len && heap[r] > heap[new])
        {
            new = r;
        }
        if (new == idx)
        {
            return;
        }

        int temp = heap[idx];
        heap[idx] = heap[new];
        heap[new] = temp;
        
        idx = new;
    }
}

// int heap_extract(int *heap, int *len) 
// {
//     int ret = *heap;
//     *heap = heap[--*len];
//     heapify_down(heap, *len, 0);
//     return ret;
// }

void heapify(int *arr, int len) 
{
    for (int i = len / 2; i >= 0; i--)
    {
        heapify_down(arr, len, i);
    }
}

long long pickGifts(int* gifts, int giftsSize, int k) 
{
    long res = 0;
    
    heapify(gifts, giftsSize);
    
    while (k--) 
    {
        int val = *gifts;
        if (val == 1) break;
        *gifts = sqrt(*gifts);
        heapify_down(gifts, giftsSize, 0);
    }
    
    for (int i = 0; i < giftsSize; i++)
    {
        res += gifts[i];
    }

    return res;
}

int main()
{
    int arr[] = {25,64,9,4,100};

    printf("%lld\n",pickGifts(arr,5,4));
    return 0;
}