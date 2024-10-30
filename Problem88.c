//You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
//Merge nums1 and nums2 into a single array sorted in non-decreasing order.

#include<stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int i = m - 1;
    int j = n - 1;
    int last = nums1Size - 1;

    while (last>=0)
    {
        if (i<0)
        {
            nums1[last--] = nums2[j--];
        }
        else if (j<0)
        {
            nums1[last--] = nums1[i--];
        }
        else if (nums1[i] > nums2[j])
        {
            nums1[last] = nums1[i];
            last--;
            i--;
        }
        else
        {
            nums1[last--] = nums2[j--];
        }
    }
}


int main()
{

    int nums1[] = {1,2,3,0,0,0};
    int nums2[] = {2,5,6};

    merge(nums1,6,3,nums2,3,3);
    for(int i = 0;i < 6;i++)
    {
        printf("%d\n",nums1[i]);
    }
    return 0;
}