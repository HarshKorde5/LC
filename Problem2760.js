/*
You are given a 0-indexed integer array nums and an integer threshold.

Find the length of the longest subarray of nums starting at index l and ending at index r (0 <= l <= r < nums.length) that satisfies the following conditions:

nums[l] % 2 == 0
For all indices i in the range [l, r - 1], nums[i] % 2 != nums[i + 1] % 2
For all indices i in the range [l, r], nums[i] <= threshold
Return an integer denoting the length of the longest such subarray.

Note: A subarray is a contiguous non-empty sequence of elements within an array. 
*/

/**
 * @param {number[]} nums
 * @param {number} threshold
 * @return {number}
 */
var longestAlternatingSubarray = function(nums, threshold) {
    let l = 0,r = 0,maxLen = 0;

    while(r < nums.length)
    {
        if(nums[r] % 2 == 0 && nums[r] <= threshold)
        {
            l = r;

            while(r+1 < nums.length && nums[r]%2 != nums[r+1]%2 && nums[r+1] <= threshold)
            {
                r++;
            }

            maxLen = maxLen > r - l + 1 ? maxLen : r - l + 1;

        }

        r++;
    }

    return maxLen;
};

console.log(longestAlternatingSubarray([3,2,5,4],5));
