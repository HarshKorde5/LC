/**
Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.
 */

/**
 * @param {string} s
 * @param {number} k
 * @return {boolean}
 */
var canConstruct = function(s, k) {
    if(s.length < k){
        return false;
    }
    if(s.length === k){
        return true;
    }

    let odd = 0;
    let freq = new Array(26).fill(0);

    for(const ch of s){
        freq[ch.charCodeAt(0)-'a'.charCodeAt(0)]++;
    }

    for(let i = 0;i < 26;i++){
        if(freq[i] % 2 === 1){
            odd++;
        }
    }

    return (odd <= k);
};

let s = "annabelle", k = 2
console.log(canConstruct(s,k));