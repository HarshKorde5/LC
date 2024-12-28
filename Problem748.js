/**
 * @param {string} licensePlate
 * @param {string[]} words
 * @return {string}
 */
var shortestCompletingWord = function(licensePlate, words) {

    licensePlate = licensePlate.toLowerCase().replace(/[\d\s]/g,'');
    const sorted = [...words].sort((a,b)=>a.length - b.length);

    for(const word of sorted)
    {
        let copyLicense = licensePlate;

        for(let i = 0;i < word.length;i++)
        {
            copyLicense = copyLicense.replace(word[i],'');
            if(!copyLicense)
            {
                return word;
            }
        }
    }
};

console.log(shortestCompletingWord("1s3 PSt",["step","steps","stripe","stepple"]));