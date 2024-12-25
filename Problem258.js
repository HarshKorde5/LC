/*
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
*/

/**
 * @param {number} num
 * @return {number}
 */
var addDigits = function (num) {
    let sum = 0;

    while (num > 9) {
        sum = 0;
        while (num != 0) {
            let digit = num % 10;
            sum += digit;
            num = Math.floor(num / 10);
        }
        num = sum;
    }
    return num;

};

console.log(addDigits(38));