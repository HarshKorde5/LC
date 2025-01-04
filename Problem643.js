/**
    You are given an integer array nums consisting of n elements, and an integer k.

    Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.
 */


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findMaxAverage = function (nums, k) {
    let start = 0, end = k - 1;
    const n = nums.length;
    let sum = 0;

    //intial calculation of window sum
    for (let i = 0; i < k; i++) {
        sum += nums[i];
    }

    let maxSum = sum;
    start++;
    end++;

    for (; end < n; end++, start++) {
        sum -= nums[start - 1];
        sum += nums[end];

        maxSum = maxSum > sum ? maxSum: sum;
    }

    return maxSum / k;

};

console.log(findMaxAverage([1,12,-5,-6,50,3],4))