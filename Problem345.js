/*
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
*/

/**
 * @param {string} s
 * @return {string}
 */
var reverseVowels = function(str) {
    
    let l = 0;
    let r = str.length - 1;
    str = str.split('');

    
    const vowels = "aeiouAEIOU";

    while(l < r)
    {
        while(l < r && !vowels.includes(str[l]))
        {
            l++;
        }
        
        while(r > l && !vowels.includes(str[r]))
        {
            r--;
        }

        let temp = str[l];
        str[l] = str[r];
        str[r] = temp;

        l++;
        r--;
    }

    return str.join('');
};