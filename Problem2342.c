/*
You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].

Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.
*/

#include<stdio.h>
#include<stdlib.h>

int sumOfDigits(int num){
    int sum = 0;
    while(num != 0){
        sum += (num % 10);
        num /= 10;
    }
    return sum;
}
///////////////////////////////////////////////////////
//  Brute Force : TLE
///////////////////////////////////////////////////////
int maximumSum1(int* nums, int numsSize) {


    int sumArray[numsSize];

    for(int i = 0;i < numsSize;i++){
        sumArray[i] = sumOfDigits(nums[i]);
    }

    int max = 0;

    for(int i = 0;i < numsSize - 1;i++){
        for(int j = i + 1;j < numsSize;j++){
            if(sumArray[i] == sumArray[j]){
                int curr = nums[i] + nums[j];
                max = max > curr ? max : curr;
            }
        }
    }

    return max != 0 ? max : -1;
}

///////////////////////////////////////////////////////
//  Maximum sum of numbers upto 10^9 is 82
//  This gives us the size of our hash table
//  Directly allowing us to store sum for each
//  hash index if it's available
///////////////////////////////////////////////////////
typedef struct {
    int first;
    int second;
} Hash;

int maximumSum2(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    int MaxSum = -1;
    Hash* Hashtable = (Hash*)calloc(82, sizeof(Hash));
    
    for (int i = 0; i < 82; i++) {
        Hashtable[i].first = -1;
        Hashtable[i].second = -1;
    }

    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        int sum = 0;

 
 
        while (num > 0) {
            sum += num % 10;
            
            num /= 10;
            
        }

        if (Hashtable[sum].first == -1 && Hashtable[sum].second == -1) {
            Hashtable[sum].first = nums[i];
        } else if (Hashtable[sum].second == -1) {
            Hashtable[sum].second = nums[i];
            MaxSum = (MaxSum > (Hashtable[sum].first + Hashtable[sum].second)) ? MaxSum : (Hashtable[sum].first + Hashtable[sum].second);
        } else {
            if (Hashtable[sum].first >= Hashtable[sum].second) {
                Hashtable[sum].second = (Hashtable[sum].second >= nums[i]) ? Hashtable[sum].second : nums[i];
            } else {
                Hashtable[sum].first = (Hashtable[sum].first >= nums[i]) ? Hashtable[sum].first : nums[i];
            }
            MaxSum = (MaxSum > (Hashtable[sum].first + Hashtable[sum].second)) ? MaxSum : (Hashtable[sum].first + Hashtable[sum].second);
        }
    }
    free(Hashtable);
    return MaxSum;
}


int maximumSum(int* nums, int numsSize) {
    int maxSum = -1;
    int maxValues[100] = {0}; 

    for (int i = 0; i < numsSize; i++) {
        int digitSum = sumOfDigits(nums[i]);

        if (maxValues[digitSum] > 0) {
            int pairSum = maxValues[digitSum] + nums[i];
            if (pairSum > maxSum) {
                maxSum = pairSum;
            }
        }
        if (nums[i] > maxValues[digitSum]) {
            maxValues[digitSum] = nums[i];
        }
    }

    return maxSum;

}

int main(){
    int nums[] = {18,43,36,13,7};

    printf("%d\n",maximumSum(nums,5));

    return 0;
}