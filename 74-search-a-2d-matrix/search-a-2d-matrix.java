class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;

        int start = 0, end = m * n - 1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            int row = mid / n, col = mid % n ;

            if(target == matrix[row][col]){
                return true;
            }else if(target > matrix[row][col]){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }

        return false;
    }
}