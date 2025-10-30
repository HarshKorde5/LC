/*
You are given an integer array target. You have an integer array initial of the same size as target with all elements initially zeros.

In one operation you can choose any subarray from initial and increment each value by one.

Return the minimum number of operations to form a target array from initial.

The test cases are generated so that the answer fits in a 32-bit integer.
*/
#include<stdio.h>

/*
If current element is stepping down from previous element (target[i] < target[i - 1]),
this means we might have already climbed this current element level while climbing the previous higher level.

But if current element is bigger and previous element is smaller (target[i] > target[i - 1])
this means we need to climb up to the current element from previous one, (we need efforts to climb XD)
so effort needs to be counted in case of climbing which will be the difference between current step and previous step

*/
int minNumberOperations(int* target, int targetSize) {
    int ops = target[0];

    for(int i = 1; i < targetSize; i++){
        if (target[i] > target[i - 1]) {
            ops += target[i] - target[i - 1];
        }
    }


    return ops;
}

int main(){

    int target[] = {2,3,4,2,5,7};

    int n = 6;

    printf("Minimum number of operations required to convert initial array to target array is : %d\n",minNumberOperations(target,n));
    return 0;
}