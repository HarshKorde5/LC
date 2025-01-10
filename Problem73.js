//Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.


/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function (mat) {
    let r = new Set(), c = new Set();


    for (let i = 0; i < mat.length; i++) {
        for (let j = 0; j < mat[i].length; j++) {
            if (mat[i][j] === 0) {
                r.add(i);
                c.add(j);
            }
        }
    }


    const row = mat.length;
    const col = mat[0].length;
    r.forEach((i) => {
        let j = 0;
        while (j < col) {
            mat[i][j] = 0;
            j++;
        }
    })
    c.forEach((j) => {
        let i = 0;
        while (i < row) {
            mat[i][j] = 0;
            i++;
        }
    })
    return mat
};

let matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]

console.log(setZeroes(matrix));