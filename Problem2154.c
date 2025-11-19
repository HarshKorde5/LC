/*
You are given an array of integers nums. You are also given an integer original which is the first number that needs to be searched for in nums.

You then do the following steps:

If original is found in nums, multiply it by two (i.e., set original = 2 * original).
Otherwise, stop the process.
Repeat this process with the new number as long as you keep finding the number.
Return the final value of original.
*/

#include<stdio.h>
#include<uthash.h>
#include<stdbool.h>


typedef struct{
    int key;
    UT_hash_handle hh;
}HashItem;

HashItem* hashFindItem(HashItem** obj, int key){
    HashItem* pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem** obj, int key){
    if(hashFindItem(obj, key)){
        return false;
    }

    HashItem* pEntry = (HashItem*)malloc(sizeof(HashItem));
    pEntry->key = key;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

void hashFree(HashItem** obj){
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp){
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

int findFinalValue(int* nums, int numsSize, int original) {


    HashItem* set = NULL;
    for(int i = 0;i < numsSize; i++){
        hashAddItem(&set, nums[i]);
    }

    while(hashFindItem(&set, original)){
        original *= 2;
    }

    hashFree(&set);
    return original;

}

int findFinalValue_2(int* nums, int numsSize, int original) {

    int cmp(const void* a, const void* b){
        return (*(int*)a - *(int*)b);
    }

    qsort(nums, numsSize, sizeof(int), cmp);

    for(int i = 0; i < numsSize; i++){
        if(original == nums[i]){
            original *= 2;
        }
    }

    return original;
}

int findFinalValue_1(int* nums, int numsSize, int original) {
    int i = 0;

    do {
        if (nums[i] == original) {
            original *= 2;
            i = 0;
        } else {
            i++;
        }
    } while (i < numsSize);

    return original;
}


int main(){
    int nums[] = {5,3,6,1,12};
    int n = 5;
    int og = 3;

    int ret = findFinalValue(nums,n,og);

    printf("Last Original value is : %d\n",ret);

    return 0;
}