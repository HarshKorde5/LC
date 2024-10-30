/*
Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int count[201];

int cmp(const void* a, const void* b){
    int int_a = *(int*)a;
    int int_b = *(int*)b;

    if(count[int_a + 100] != count[int_b + 100]){
        return count[int_a + 100] - count[int_b + 100];
    }else return int_b - int_a;
}
int* frequencySort(int* nums, int numsSize, int* returnSize) {
    int i;
    memset(count, 0, sizeof(count));

    for(i = 0; i < numsSize; i++){
        count[nums[i] + 100]++;
    }

    qsort(nums, numsSize, sizeof(int),cmp);
    
    *returnSize = numsSize;
    return nums;
}


int main()
{
    return 0;
}