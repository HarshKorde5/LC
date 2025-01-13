/**
You are given a string s.

You can perform the following process on s any number of times:

Choose an index i in the string such that there is at least one character to the left of index i that is equal to s[i], and at least one character to the right that is also equal to s[i].
Delete the closest character to the left of index i that is equal to s[i].
Delete the closest character to the right of index i that is equal to s[i].
Return the minimum length of the final string s that you can achieve.
 */

/**
 * @param {string} s
 * @return {number}
 */
var minimumLength = function(s) {
    const freq = new Array(26).fill(0);

    for(const ch of s){
        freq[ch.charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }
    let cnt = 0;

    for(let i = 0;i < 26;i++){
        if(freq[i] !== 0){
            if(freq[i] % 2 === 1){
                cnt += 1
            }else{
                cnt += 2;
            }
        }
    }

    return cnt;
};

console.log(minimumLength("abaacbcbb"));