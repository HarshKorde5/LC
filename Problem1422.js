/**
 * Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).

The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.


 */

/**
 * @param {string} s
 * @return {number}
 */
var maxScore = function(s) {
    let ones = 0;
    let zeros = 0;
    let best = Number.MIN_SAFE_INTEGER;

    for(let i = 0;i < s.length - 1;i++){
        if(s[i] === '1'){
            ones++;
        }else{
            zeros++;
        }
        best = best > zeros - ones ? best : zeros - ones;
    }

    if(s[s.length - 1] == '1'){
        ones++;
    }

    return best + ones;
};

console.log(maxScore("011101"));