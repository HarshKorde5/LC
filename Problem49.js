/*
Given an array of strings strs, group the 
anagrams
 together. You can return the answer in any order.
*/


/**
 * @param {string[]} strs
 * @return {string[][]}
 */
    
var groupAnagrams = function(strs){
 
    const map = new Map(); 
 
    for(let i = 0; i < strs.length; i++)
    {
        let key = strs[i].split('').sort().join('');
 
        if(map.has(key)) {
            map.get(key).push(strs[i]);
        } else {
            map.set(key,[strs[i]]);
        }
    }
 
 
    const mapValues = Array.from(map.values());
    
    return mapValues;   
};

let strs = ["eat","tea","tan","ate","nat","bat"];

console.log(groupAnagrams(strs));

