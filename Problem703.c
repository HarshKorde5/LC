/*
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.
*/
/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 
 * kthLargestFree(obj);
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    int k;
    int *nums;
    int size;
} KthLargest,*KKthLargest;


KthLargest* kthLargestCreate(int k, int* nums, int numsSize)
{
    KKthLargest obj = (KKthLargest)malloc(sizeof(KthLargest));
    obj->k = k;
    obj->nums = (int*)calloc(sizeof(int),k);
    obj->size = 0;

    for(int i = 0;i < numsSize;i++)
    {
        kthLargestAdd(obj,nums[i]);
    }

    return obj;
}

void insert(int *arr,int n,int val)
{
    int i = n - 1;

    while(i >= 0 && arr[i] < val)
    {
        arr[i + 1] = arr[i];
        i--;
    }

    arr[i + 1] = val;
}

int kthLargestAdd(KthLargest* obj, int val)
{
    if(obj->size < obj->k)
    {
        insert(obj->nums,obj->size,val);
        obj->size++;
    }
    else if(val > obj->nums[obj->size - 1])
    {
        insert(obj->nums,obj->size - 1,val);
    }

    return obj->nums[obj->size - 1];
}

void kthLargestFree(KthLargest* obj)
{
    free(obj->nums);
    free(obj);
}

int main()
{
    int arr[] = {4,5,8,2};

    struct KthLargest obj(3,arr,4);
    
    KthLargestAdd(obj,3);
    KthLargestAdd(obj,5);
    KthLargestAdd(obj,10);
    KthLargestAdd(obj,9);
    KthLargestAdd(obj,4);


    return 0;
}