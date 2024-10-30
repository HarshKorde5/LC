// Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.

// A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.


/**
 * @param {number[][]} matrix
 * @return {boolean}
 */
var isToeplitzMatrix = function(matrix) 
{
    let flag = true;

    for(let i = 0;i < matrix.length-1;i++)
    {
        for(let j = 0;j < matrix[i].length-1;j++)
        {
            if(matrix[i][j] != matrix[i+1][j+1])
            {
                flag = false;
                break;
            }
        }
        if(flag == false)   break;
    }
    

    return flag;
};