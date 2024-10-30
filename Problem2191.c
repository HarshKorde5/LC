/*
You are given a 0-indexed integer array mapping which represents the mapping rule of a shuffled decimal system. mapping[i] = j means digit i should be mapped to digit j in this system.

The mapped value of an integer is the new integer obtained by replacing each occurrence of digit i in the integer with mapping[i] for all 0 <= i <= 9.

You are also given another integer array nums. Return the array nums sorted in non-decreasing order based on the mapped values of its elements.

Notes:

Elements with the same mapped values should appear in the same relative order as in the input.
The elements of nums should only be sorted based on their mapped values and not be replaced by them.
*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *map_function(int *mapping,int *nums,int numsSize)
{
    int *ret = (int*)malloc(sizeof(int)*numsSize);
    int i = 0;
    int k = 0;

    for(i = 0;i < numsSize;i++)
    {    
        int new_no = 0;
        int no = nums[i];
        while(no != 0)
        {
            new_no = ((new_no * 10) + (mapping[no%10]));
            no /= 10;
        }
        int new = 0;
        while(new_no != 0)
        {
            new = ((new * 10) + (new_no % 10));
            new_no /= 10;
        }

        ret[k++] = new;
    }

    return ret;
}

void swap(int *p1,int *p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int partition(int *nums,int *arr,int low,int high)
{
    int pivot = arr[high];

    int i = low - 1;

    for(int j = low;j < high;j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(&nums[i],&nums[j]);
        }
    }

    swap(&nums[i + 1], &nums[high]);
    return (i + 1);
}

void QuickSort(int *nums,int *arr,int low,int high)
{
    if(low < high)
    {
        int pi = partition(nums,arr,low,high);

        QuickSort(nums,arr,low,pi-1);
        QuickSort(nums,arr,pi+1,high);
    }
}

int* sortJumbled(int* mapping, int mappingSize, int* nums, int numsSize, int* returnSize)
{
    int *mapped_arr = map_function(mapping,nums,numsSize);

    QuickSort(nums,mapped_arr,0,numsSize-1);

    free(mapped_arr);

    int *ret = (int *)malloc(sizeof(int)*numsSize);

    for(int i = 0;i < numsSize;i++)
    {
        ret[i] = nums[i];
    }

    *returnSize = numsSize;
    return ret;
    
}