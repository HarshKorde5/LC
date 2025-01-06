/*
Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.


*/


/**
 * @param {number[]} nums
 * @return {number}
 */
var pivotIndex1 = function(nums) {
    
    const total = nums.reduce((a,b) => a + b,0);
    let leftTotal = 0;

    for(let i = 0;i < nums.length;i++){
        let rightTotal = total - leftTotal - nums[i];

        if(rightTotal === leftTotal){
            return i;
        }

        leftTotal += nums[i];
    }

    return -1;
    
};

var pivotIndex2 = function(nums) {
    const n = nums.length;
    if(n === 1){
        return 0;
    }

    let left = new Array(n).fill(0);
    let right = new Array(n).fill(0);

    left[0] = nums[0];
    right[n - 1] = nums[n - 1];

    for(let i = 1;i < n;i++){
        left[i] = left[i - 1] + nums[i];
        right[n - i - 1] = right[n - i] + nums[n - i - 1];
    }

    if(right[1] === 0){
        return 0;
    }

    for(let i = 1;i < n - 1;i++){
        if(left[i - 1] === right[i + 1]){
            return i;
        }
    }

    if(left[n - 2] === 0){
        return n - 1;
    }

    return -1;

};

var pivotIndex = function(nums) {
    const n = nums.length;
    if(n === 0) return -1;

    let leftSum = 0,rightSum = 0;
    rightSum = nums.reduce((a,b) => a+b,0);

    for(let i = 0;i < n;i++){
        rightSum -= nums[i];
        if(rightSum === leftSum){
            return i;
        }

        leftSum += nums[i];
    }

    return -1;

};

console.log(pivotIndex([1,7,3,6,5,6]));