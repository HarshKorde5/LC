
/**
You are given two 0-indexed integer permutations A and B of length n.

A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.

Return the prefix common array of A and B.

A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.
 */

/**
 * @param {number[]} A
 * @param {number[]} B
 * @return {number[]}
 */
var findThePrefixCommonArray1 = function(A, B) {
    const n = A.length;

    const result = new Array(n);
    const freq = new Array(n+1).fill(0);
    let count = 0;

    for(let i = 0;i < n;i++){
        if(++freq[A[i]] == 2){
            count++;
        }
        
        if(++freq[B[i]] == 2){
            count++;
        }

        result[i] = count;
    }

    return result;
};

var findThePrefixCommonArray = function(A, B) {
    const n = A.length;

    const result = new Array(n).fill(0);

    const elementsInA = new Set();
    const elementsInB = new Set();

    for(let i = 0;i < n;i++){
        elementsInA.add(A[i]);
        elementsInB.add(B[i]);

        let commonCount = 0;

        for(const no of elementsInA){
            if(elementsInB.has(no)){
                ++commonCount;
            }
        }

        result[i] = commonCount;
    }

    return result;
};

const A = [1,3,2,4], B = [3,1,2,4];

console.log(findThePrefixCommonArray(A,B))