/**
 Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
 */

/**
 * @param {number[]} nums
 * @return {number[]}
 */

//////////////////////////////////////////////////
//  Brute Force using Map O(n+m) : O(m)
//////////////////////////////////////////////////
var majorityElement1 = function (arr) {


    const n = arr.length;
    let map = new Map();
    for (let i = 0; i < n; i++) {
        map.set(arr[i], (map.get(arr[i]) || 0) + 1);
    }

    const result = [];
    for (const [key, value] of map.entries()) {
        if (value > n / 3) {
            result.push(key);
        }
    }
    return result;

};

////////////////////////////////////////////////////////
//  Boyer-Moore Majority Vote Algorithm O(n) : O(1)
////////////////////////////////////////////////////////
var majorityElement = function(nums) {
    let majority1 = 0;
    let majority2 = 0;
    let count1 = 0;
    let count2 = 0;

    for (const num of nums) {
        if (num === majority1) {
            count1++;
        } else if (num === majority2) {
 
            count2++;
        } else if (count1 === 0) {
            majority1 = num;
            count1++;
        } else if (count2 === 0) {
            majority2 = num;
            count2++;
        } else {
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;

    for (const num of nums) {
        if (num === majority1) {
            count1++;
        } else if (num === majority2) {
            count2++;
        }
    }

    const res = [];
    const n = nums.length;

    if (count1 > Math.floor(n / 3)) {
        res.push(majority1);
    }
    if (count2 > Math.floor(n / 3)) {
        res.push(majority2);
    }

    return res;    
}

console.log(majorityElement([3,2,3]));