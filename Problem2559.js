
/*

You are given a 0-indexed array of strings words and a 2D array of integers queries.

Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.

Return an array ans of size queries.length, where ans[i] is the answer to the ith query.

Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.
*/


/**
 * @param {string[]} words
 * @param {number[][]} queries
 * @return {number[]}
 */

/////////////////////////////////////////////////////////
//  Brute Force
/////////////////////////////////////////////////////////
var vowelStrings1 = function(words, queries) {

    let temp = [];
    const vowels = new Set(['a','e','i','o','u']);

    for(let i = 0;i < words.length;i++){
        if(vowels.has(words[i][0]) && vowels.has(words[i][words[i].length - 1])){
            temp.push([words[i],i]);
        }
    }

    // console.log(temp);
    let result = [];

    for(let i = 0;i < queries.length;i++){
        let count = 0;
        for(let j = 0;j < temp.length;j++){
            if(temp[j][1] >= queries[i][0] && temp[j][1] <= queries[i][1]){
                count++;
            }
        }
        result.push(count);
    }

    return result;
};

////////////////////////////////////////////////////////
//  Prefix Sum
////////////////////////////////////////////////////////
var vowelStrings = function(words, queries) {
    let result = [];
    let vowels = new Set(['a','e','i','o','u']);
    let prefixSum = [];

    let sum = 0;

    for(let i = 0;i < words.length;i++){
        let curr = words[i];

        if(vowels.has(curr[0]) && vowels.has(curr[curr.length -1])){
            sum++;
        }
        prefixSum.push(sum);
    }

    // console.log(prefixSum);

    for(let i = 0;i < queries.length;i++){
        let curr = queries[i];
        result.push(prefixSum[curr[1]] - (curr[0] == 0 ? 0 : prefixSum[curr[0] - 1]));
    }

    return result;
}   

let words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]];

console.log(vowelStrings(words,queries));