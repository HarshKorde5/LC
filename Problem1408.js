
/*
Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.

A substring is a contiguous sequence of characters within a string
*/

/**
 * @param {string[]} words
 * @return {string[]}
 */
var stringMatching = function(words) {

    const result = [];
    // words = words.sort((a,b)=>a.length-b.length);
    
    for(let i = 0;i < words.length;i++){
        for(let j = 0;j < words.length;j++){
            if(i != j){
                if(words[j].indexOf(words[i]) !== -1){
                    result.push(words[i]);
                    break;
                }
            }
        }
    }

    return result;
};

let words = ["mass","as","hero","superhero"];

console.log(stringMatching(words));