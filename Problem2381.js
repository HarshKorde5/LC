/*
You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.

Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').

Return the final string after all such shifts to s are applied.
*/

/**
 * @param {string} s
 * @param {number[][]} shifts
 * @return {string}
 */

//////////////////////////////////////////////////////////
//  Brute Force : TLE
//////////////////////////////////////////////////////////
var shiftingLetters1 = function(str, shifts) {
    let s = str.split('');
    for(const shift of shifts){
        for(let i = shift[0];i <= shift[1];i++){
            if(shift[2] == 1){
                if(s[i] === 'z'){
                    s[i] = 'a';
                }else{
                    s[i] = String.fromCharCode(s[i].charCodeAt(0) + 1)
                }
            }else{
                if(s[i] === 'a'){
                    s[i] = 'z';
                }else{
                    s[i] = String.fromCharCode(s[i].charCodeAt(0) - 1)
                }
            }
        }
    }

    return s.join('');
};

//////////////////////////////////////////////////////////
//  Difference array
//////////////////////////////////////////////////////////
var shiftingLetters = function(s, shifts) {
    const n = s.length;
    let diffArray = new Array(n).fill(0);

    for(const shift of shifts){
        if(shift[2] == 1){
            diffArray[shift[0]]++;

            if(shift[1] + 1 < n + 1){
                diffArray[shift[1] + 1]--;
            }

        }else{
            diffArray[shift[0]]--;

            if(shift[1] + 1 < n + 1){
                diffArray[shift[1] + 1]++;
            }
        }
    }

    let result = [];
    let numberOfShifts = 0;
    
    for(let i = 0;i < n;i++){
        numberOfShifts = (numberOfShifts + diffArray[i]) % 26;

        if(numberOfShifts < 0){
            numberOfShifts += 26;
        }

        result[i] = String.fromCharCode(97 + (s[i].charCodeAt(0) - 97 + numberOfShifts) % 26);
    }

    return result.join('');
}

let s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]];

console.log(shiftingLetters(s,shifts))