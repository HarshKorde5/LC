/*
You are given a 0-indexed array nums of length n.

The distinct difference array of nums is an array diff of length n such that diff[i] is equal to the number of distinct elements in the suffix nums[i + 1, ..., n - 1] subtracted from the number of distinct elements in the prefix nums[0, ..., i].

Return the distinct difference array of nums.

Note that nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j inclusive. Particularly, if i > j then nums[i, ..., j] denotes an empty subarray.
*/

/**
 * @param {number[]} nums
 * @return {number[]}
 */
var distinctDifferenceArray1 = function(nums) 
{
    const result = [];

    for(let i = 0;i < nums.length;i++)
    {
        let prefixset = new Set();
        let suffixset = new Set();
        
        let prefix = nums.slice(0,i+1);
        let suffix = nums.slice(i+1);

        prefix.forEach(val => prefixset.add(val));
        suffix.forEach(val => suffixset.add(val));

        result.push(prefixset.size - suffixset.size);
    }

    return result;
};

var distinctDifferenceArray2 = function(nums) 
{
    const result = [];

    for(let i = 0;i < nums.length;i++)
    {
        let prefixset = new Set(nums.slice(0,i+1));
        let suffixset = new Set(nums.slice(i+1));
        
        result.push(prefixset.size - suffixset.size);
    }

    return result;
};

var distinctDifferenceArray = function(nums) 
{
    const result = [];
    const n = nums.length;
    const prefix = [];
    const suffix = [];
    const prefixset = new Set();
    const suffixset = new Set();

    for(let i = 0;i < n;i++)
    {
        prefixset.add(nums[i]);
        prefix.push(prefixset.size);


        suffix.push(suffixset.size);
        suffixset.add(nums[n-i-1]);

    }

    for(let i = 0;i < n;i++)
    {
        result.push(prefix[i] - suffix[n-i-1]);
    }

    return result;
}


let nums = [1,2,3,4,5];

console.log(distinctDifferenceArray(nums));