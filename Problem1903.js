
/*
You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.
*/


/**
 * @param {string} num
 * @return {string}
 */

////////////////////////////////////////////////////////
// BigInt issue
////////////////////////////////////////////////////////
var largestOddNumber1 = function (s) {
    let num = Number(s);
    while (num > 0) {
        if (num % 2 !== 0) return String(num);
        num = Math.floor(num / 10);
    }

    return "";
};

var largestOddNumber = function (s) {
    let arr = s.split('');
    let i = 0;
    for(i = arr.length-1; i >= 0; i--) {
       if(Number(arr[i]) % 2) {
           arr.length = i+1;
           break;
       }
   }
   return i === -1 ? "" : arr.join('');
}


console.log(largestOddNumber("3527"))