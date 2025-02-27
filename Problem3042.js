/**
You are given a 0-indexed string array words.

Let's define a boolean function isPrefixAndSuffix that takes two strings, str1 and str2:

isPrefixAndSuffix(str1, str2) returns true if str1 is both a 
prefix
 and a 
suffix
 of str2, and false otherwise.
For example, isPrefixAndSuffix("aba", "ababa") is true because "aba" is a prefix of "ababa" and also a suffix, but isPrefixAndSuffix("abc", "abcd") is false.

Return an integer denoting the number of index pairs (i, j) such that i < j, and isPrefixAndSuffix(words[i], words[j]) is true.
 */


/**
 * @param {string[]} words
 * @return {number}
 */

function isPrefixAndSuffix(str1,str2){

    // return (str2.startsWith(str1) && str2.endsWith(str1));

    if(str2.length < str1.length)   return false;
    
    let i = 0;
    let j = (str2.length - str1.length);
    let k = 0;

    while(k < str1.length){
        
        if(str2[i] !== str1[k] || str2[j] !== str1[k]){
            return false;
        }

        i++;
        j++;
        k++;
    }

    return true;
}


var countPrefixSuffixPairs = function(words) {
    
    let count = 0;

    for(let i = 0;i < words.length;i++){

        for(let j = i + 1;j < words.length;j++){
            if(isPrefixAndSuffix(words[i],words[j])){
                count++;
            }
        }
    }

    return count;
};

console.log(countPrefixSuffixPairs(["a","aba","ababa","aa"]))