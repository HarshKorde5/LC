
#include<stdio.h>



int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int minDifference(int* nums, int numsSize) {
    // If the length of the array is less than or equal to 4, return 0
    if (numsSize <= 4) {
        return 0;
    }

    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);

    // Calculate the minimum difference considering different scenarios
    // 1. Change the three largest elements
    int option1 = nums[numsSize - 4] - nums[0];
    // 2. Change the two largest elements and the smallest element
    int option2 = nums[numsSize - 3] - nums[1];
    // 3. Change the largest element and the two smallest elements
    int option3 = nums[numsSize - 2] - nums[2];
    // 4. Change the three smallest elements
    int option4 = nums[numsSize - 1] - nums[3];

    // Return the minimum difference
    int minDiff = option1;
    if (option2 < minDiff) minDiff = option2;
    if (option3 < minDiff) minDiff = option3;
    if (option4 < minDiff) minDiff = option4;

    return minDiff;
}

int main()
{
    int arr[] = {1,5,0,10,14};

    int ret = minDifference(arr,5);

    
    return 0;
}