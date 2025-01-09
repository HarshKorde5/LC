/**
You are given an array of strings words and a string pref.

Return the number of strings in words that contain pref as a prefix.

A prefix of a string s is any leading contiguous substring of s.
 */

/**
 * @param {string[]} words
 * @param {string} pref
 * @return {number}
 */
var prefixCount = function(words, pref) {
    return (words.filter((word)=>word.startsWith(pref))).length;
};

var prefixCount1 = function(words, pref) {
    let count = 0;
    words.forEach((word)=>{
        for(let i = 0;i < pref.length;i++){
            if(word[i] !== pref[i]){
                return;
            }
        }
        count++;
    })

    return count;
};

let words = ["pay","attention","practice","attend"], pref = "at"
console.log(prefixCount(words,pref))