/**
You are given two string arrays words1 and words2.

A string b is a subset of string a if every letter in b occurs in a including multiplicity.

For example, "wrr" is a subset of "warrior" but is not a subset of "world".
A string a from words1 is universal if for every string b in words2, b is a subset of a.

Return an array of all the universal strings in words1. You may return the answer in any order.
 */


/**
 * @param {string[]} words1
 * @param {string[]} words2
 * @return {string[]}
 */

var wordSubsets = function(words1, words2) {
    
    let main = new Array(26).fill(0);

    for(const word of words2){
        const temp = new Array(26).fill(0);

        for(const ch of word){
            temp[ch.charCodeAt(0)-'a'.charCodeAt(0)]++;
        }

        for(let i = 0;i < 26;i++){
            main[i] = main[i] > temp[i] ? main[i] : temp[i];
        }
    }

    const result = [];

    for(const word of words1){
        const temp = new Array(26).fill(0);

        for(const ch of word){
            temp[ch.charCodeAt(0) - 'a'.charCodeAt(0)]++;
        }

        let isUniversal = true;

        for(let i = 0;i < 26;i++){
            if(temp[i] < main[i]){
                isUniversal = false;
                break;
            }
        }

        if(isUniversal){
            result.push(word);
        }
    }

    return result;
};

let words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"];

console.log(wordSubsets(words1,words2));