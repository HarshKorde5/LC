/*
You are given two arrays rowSum and colSum of non-negative integers where rowSum[i] is the sum of the elements in the ith row and colSum[j] is the sum of the elements of the jth column of a 2D matrix. In other words, you do not know the elements of the matrix, but you do know the sums of each row and column.

Find any matrix of non-negative integers of size rowSum.length x colSum.length that satisfies the rowSum and colSum requirements.

Return a 2D array representing any matrix that fulfills the requirements. It's guaranteed that at least one matrix that fulfills the requirements exists.
*/

int** restoreMatrix(int* rowSum, int rowSumSize, int* colSum, int colSumSize, int* returnSize, int** returnColumnSizes) {
    int** res = (int**)malloc(rowSumSize * sizeof(int*));
    for (int i = 0; i < rowSumSize; i++) {
        res[i] = (int*)calloc(colSumSize, sizeof(int));
    }

    int cur_row = 0, cur_col = 0;
    *returnSize = rowSumSize;
    *returnColumnSizes = (int*)malloc(rowSumSize * sizeof(int));
    for (int i = 0; i < rowSumSize; i++) {
        (*returnColumnSizes)[i] = colSumSize;
    }

    while (cur_row < rowSumSize || cur_col < colSumSize) {
        if (cur_row >= rowSumSize) {
            res[rowSumSize - 1][cur_col] = colSum[cur_col];
            cur_col++;
            continue;
        } else if (cur_col >= colSumSize) {
            res[cur_row][colSumSize - 1] = rowSum[cur_row];
            cur_row++;
            continue;
        }

        int value_to_put = rowSum[cur_row] < colSum[cur_col] ? rowSum[cur_row] : colSum[cur_col];
        rowSum[cur_row] -= value_to_put;
        colSum[cur_col] -= value_to_put;
        res[cur_row][cur_col] = value_to_put;

        // I write this as this because it's possible that rowSum[cur_row] == colSum[cur_col] and we'll want to move both row and col pointers
        if (rowSum[cur_row] == 0) {
            cur_row++;
        }
        if (colSum[cur_col] == 0) {
            cur_col++;
        }
    }
    return res;
}

int main()
{
    return 0;
}