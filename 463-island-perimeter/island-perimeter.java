class Solution {
    public int islandPerimeter(int[][] grid) {
        int m = grid.length, n = grid[0].length, res = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){

                    //top
                    res += (i - 1 < 0 || grid[i-1][j] == 0) ? 1 : 0;                    
                    //right
                    res += (j + 1 >= n || grid[i][j + 1] == 0) ? 1 : 0;
                    //bottom
                    res += (i + 1 >= m || grid[i + 1][j] == 0) ? 1 : 0;
                    //left
                    res += (j - 1 < 0 || grid[i][j-1] == 0) ? 1 : 0;
                }
            }
        }

        return res;
    }
}