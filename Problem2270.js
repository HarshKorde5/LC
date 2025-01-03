/*
You are given a 0-indexed integer array nums of length n.

nums contains a valid split at index i if the following are true:

The sum of the first i + 1 elements is greater than or equal to the sum of the last n - i - 1 elements.
There is at least one element to the right of i. That is, 0 <= i < n - 1.
Return the number of valid splits in nums.


*/

/**
* @param {number[]} nums
* @return {number}
*/
var waysToSplitArray = function(nums) {
   let prefixSum = [];
   let psum = 0;

   // let suffixSum = [];
   // let ssum = 0;

   const n = nums.length;

   for(let i = 0;i < n;i++){
       psum += nums[i]
       prefixSum.push(psum);

       // ssum += nums[n-i-1];
       // suffixSum[n-i-1] = ssum
   }

   // console.log(suffixSum);

   let count = 0;

   for(let i = 0;i < n - 1;i++){
       // if(prefixSum[i] >= suffixSum[i+1])
       if(prefixSum[i] >= (prefixSum[n-1]-prefixSum[i])){
           count++;
       }
   }

   return count;
};

console.log(waysToSplitArray([10,4,-8,7]));
