/**
A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:

It is ().
It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
It can be written as (A), where A is a valid parentheses string.
You are given a parentheses string s and a string locked, both of length n. locked is a binary string consisting only of '0's and '1's. For each index i of locked,

If locked[i] is '1', you cannot change s[i].
But if locked[i] is '0', you can change s[i] to either '(' or ')'.
Return true if you can make s a valid parentheses string. Otherwise, return false.
 */

/**
 * @param {string} s
 * @param {string} locked
 * @return {boolean}
 */

///////////////////////////////////////////////
//  ByPass not working
///////////////////////////////////////////////
var canBeValid1 = function(s, locked) {
    const n = s.length;

    if(n === 1)  return false;
    if(n % 2 === 1)  return false;

    let totalLocked = 0,lockedOpen = 0,lockedClosed = 0,unlockedOpen = 0,unlockedClosed = 0;

    for(let i = 0;i < n;i++)
    {
        if(locked[i] === "1"){
            totalLocked++;
        }

        if(s[i] === '(' && locked[i] === "1"){
            lockedOpen++;
        }

        if(s[i] === ')' && locked[i] === "1"){
            lockedClosed++;
        }

        if(s[i] === '(' && locked[i] === "0"){
            unlockedOpen++;
        }
        
        if(s[i] === ')' && locked[i] === "0"){
            unlockedClosed++;
        }
    }

    console.table([lockedOpen,lockedClosed,unlockedOpen,unlockedClosed]);


    if(lockedOpen === lockedClosed) return true;

    if(lockedOpen + unlockedOpen === lockedClosed + unlockedClosed)     return true;

    let requirement = {
        type : "",
        need : 0,
    }

    if(lockedOpen + unlockedOpen < n/2){
        requirement.type = "open";
        requirement.need = ((n/2) - (lockedOpen + unlockedOpen));
    }else{ 
        requirement.type = "closed";
        requirement.need = ((n/2) - (lockedClosed + unlockedClosed));
    }

    console.log(requirement)

    if(requirement["type"] === "open"){
        unlockedClosed = unlockedClosed - requirement["need"]
        if(unlockedClosed + lockedClosed < n/2){
            return false;
        }
    }else{

        unlockedOpen = unlockedOpen - requirement["need"]
        if(unlockedOpen + lockedOpen < n/2){
            return false;
        }
    }

    return true;

};

/////////////////////////////////////////////////////////////
//  Stack
/////////////////////////////////////////////////////////////
var canBeValid = function(s, locked) {
    const n = s.length;

    if(n % 2 === 1) return false;

    let unlocked = [],open = [];

    for(let i = 0;i < n;i++){
        if(locked[i] === '0'){
            unlocked.push(i);
        }else if(s[i] === '('){
            open.push(i);
        }else if(s[i] === ')'){
            if(open.length !== 0){
                open.pop();
            }else if(unlocked.length !== 0){
                unlocked.pop();
            }else{
                return false;
            }
        }
    }

    while(open.length !== 0 && unlocked.length !== 0 && open[open.length - 1] < unlocked[unlocked.length - 1]){
        open.pop();
        unlocked.pop();
    }

    if(open.length !== 0){
        return false;
    }

    return true;
};



let s = "))()))", locked = "010100";

console.log(canBeValid(s,locked))