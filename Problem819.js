
/*
Given a string paragraph and a string array of the banned words banned, return the most frequent word that is not banned. It is guaranteed there is at least one word that is not banned, and that the answer is unique.

The words in paragraph are case-insensitive and the answer should be returned in lowercase.
*/


/**
 * @param {string} paragraph
 * @param {string[]} banned
 * @return {string}
 */

var mostCommonWord = function(paragraph, banned) 
{
    paragraph = paragraph.toLowerCase();
    let punctuations = "!?',;. ";
    let modified = '';

    let obj = {};

    for(let i = 0;i < paragraph.length;i++)
    {
        if(!punctuations.includes(paragraph[i]))
        {
            modified += paragraph[i];
        }
        else if(modified)
        {
            obj[modified] = (obj[modified]||0)+1;
            modified = '';
        }
    }

    if(modified != '')
    {
        obj[modified] = (obj[modified]||0)+1;
    }


    let maxCount = 0;
    let maxWord = '';

    for(const key in obj)
    {
        if(obj[key] > maxCount && !banned.includes(key))
        {
            maxWord = key;
            maxCount = obj[key];
        }
    }

    return maxWord;
};


var mostCommonWord = function(paragraph, banned) 
{
    let words = paragraph.toLowerCase().split(/\W+/g);

    const map = {};

    const bannedSet = new Set(banned);

    for(const word of words)
    {
        if(!bannedSet.has(word) && word!=='')
        {
            map[word] = (map[word] || 0) + 1;
        }
    }

    let maxCount = 0;
    let frequent = '';
    
    for(const key in map)
    {
        if(map[key] > maxCount)
        {
            maxCount = map[key];
            frequent = key;
        }
    }

    // return Object.keys(map).sort((a,b) => {
    //     return map[b] - map[a]
    // }).filter(word => !banned.includes(word))[0]
    
    return frequent;
};


let paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"];

console.log(mostCommonWord(paragraph,banned));