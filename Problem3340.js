/*
You are given a string num consisting of only digits. A string of digits is called balanced if the sum of the digits at even indices is equal to the sum of digits at odd indices.

Return true if num is balanced, otherwise return false.
*/


/**
 * @param {string} num
 * @return {boolean}
 */
var isBalanced = function(num) 
{
    let arr = num.toString().split("").map(Number); 
    let sumOdd =0;
    let sumEven=0;

    for(let i=0; i<arr.length; i++)
    {
        if(i%2===0)
        {
            sumEven += arr[i];
        }
        else 
        {
            sumOdd += arr[i];
        }
    } 

    return sumEven===sumOdd;
};

console.log(isBalanced("1234"));