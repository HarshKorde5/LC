/**
You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.

In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.

Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the balls to the ith box.

Each answer[i] is calculated considering the initial state of the boxes.
 */
/**
 * @param {string} boxes
 * @return {number[]}
 */

//////////////////////////////////////////////////////////
//  Brute Force 1
//////////////////////////////////////////////////////////
var minOperations1 = function(boxes) {
    boxes = boxes.split("");
    let indexesOfOnes = [];
    for(let i = 0;i < boxes.length;i++){
        if(boxes[i] === "1"){
            indexesOfOnes.push(i);
        }
    }

    // console.log(indexesOfOnes)
    let result = new Array(boxes.length).fill(0);

    for(let i = 0;i < boxes.length;i++){
        for(let j = 0;j < indexesOfOnes.length;j++){
            result[i] = result[i] + Math.abs(indexesOfOnes[j] - i);
        }
    }

    return result;
};

//////////////////////////////////////////////////////////
//  Brute Force 2
//////////////////////////////////////////////////////////
var minOperations2 = function(boxes) {
    const n = boxes.length;
    let result = Array(n).fill(0);

    for(let i = 0;i < n;i++){

        if(boxes[i] == '1'){
            for(let j = 0;j < n;j++){
                result[j] += Math.abs(j - i);
            }
        }
    }

    return result;
};

//////////////////////////////////////////////////////////
//  Prefix Calculations
//////////////////////////////////////////////////////////
var minOperations = function(boxes) {
    const n = boxes.length;

    const result = new Array(n).fill(0);

    let movesToLeft = 0,ballsToLeft = 0;
    let movesToRight = 0,ballsToRight = 0;

    for(let i = 0;i < n;i++){

        result[i] += movesToLeft;
        ballsToLeft += (boxes[i].charCodeAt(0) - '0'.charCodeAt(0));
        movesToLeft += ballsToLeft;

        let j = n - i - 1;
        result[j] += movesToRight;
        ballsToRight += (boxes[j].charCodeAt(0) - '0'.charCodeAt(0));
        movesToRight += ballsToRight;
    }

    return result;
};

console.log(minOperations("001011"));