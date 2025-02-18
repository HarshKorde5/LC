#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int maximumProduct1(int* nums, int size) {
    int sort(const void*a,const void*b){
        return (*(int*)a-*(int*)b);
    }
    
    int prodMax=1,prodMin=1;
    qsort(nums,size,4,sort);

    if(size==3) return nums[0] * nums[1] * nums[2];
    prodMin = nums[0] * nums[1] * nums[size-1];
    prodMax = nums[size-3] * nums[size-2] * nums[size-1];

    return prodMax>prodMin ? prodMax : prodMin;
}

int maximumProduct(int* nums, int numsSize) {
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] > max1){
            max3 = max2;
            max2 = max1;
            max1 = nums[i];
        } else if(nums[i] > max2){
            max3 = max2;
            max2 = nums[i];
        } else if(nums[i] > max3){
            max3 = nums[i];
        }
        if(nums[i] < min1){
            min2 = min1;
            min1 = nums[i];
        } else if(nums[i] < min2){
            min2 = nums[i];
        }
    }
    int product1 = max1 * max2 * max3;
    int product2 = min1 * min2 * max1;
    return product1 > product2 ? product1 : product2;
}

int main(){
    int nums[] = {-4  ,-3  ,-2  ,-1  ,1  ,2  ,3  ,4};

    printf("%d\n",maximumProduct(nums,8));
    return 0;
}