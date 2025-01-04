/**
Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

A palindrome is a string that reads the same forwards and backwards.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".

 */


/**
 * @param {string} s
 * @return {number}
 */
var countPalindromicSubsequence = function(s) {
    const n = s.length;
    let count = 0;
    let used = new Set();

    for(let start = 0;start < n - 2;start++){
        if(!used.has(s[start])){
            used.add(s[start]);            
            let end = n - 1;
            while(start < end && s[start] !== s[end]){
                end--;
            }


            if(end - start - 1 >= 1){
                let checked = new Set();
                for(let k = start+1;k < end;k++){
                    if(!checked.has(s[k])){
                        checked.add(s[k]);
                        count++;
                    }
                }

            }
        }
    }

    return count;
};

console.log(countPalindromicSubsequence("bbcbaba"));