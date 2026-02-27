/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.
*/
#include <stdio.h>
#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int *result = (int*)malloc((numsSize - k + 1) * sizeof(int));
    int *deque  = (int*)malloc(numsSize * sizeof(int)); // store indices

    int front = 0, rear = -1;
    int idx = 0;

    for (int i = 0; i < numsSize; i++) {

        // 1. Remove indices out of the current window
        if (front <= rear && deque[front] < i - k + 1) {
            front++;
        }

        // 2. Remove smaller elements from back
        while (front <= rear && nums[deque[rear]] <= nums[i]) {
            rear--;
        }

        // 3. Add current index
        deque[++rear] = i;

        // 4. Store max for the window
        if (i >= k - 1) {
            result[idx++] = nums[deque[front]];
        }
    }

    *returnSize = idx;
    free(deque);
    return result;
}

int main() {
    int nums[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* result = maxSlidingWindow(nums, numsSize, k, &returnSize);

    printf("Sliding window maximums:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}