class Solution {
    private char[][] grid;
    private int m, n, res;

    public int numIslands(char[][] grid) {
        this.grid = grid;
        this.m = grid.length;
        this.n = grid[0].length;
        this.res = 0;
        for(int i = 0;i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    dfs(i,j);
                    res++;
                }
            }
        }

        return res;
    }

    private void dfs(int i, int j){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0')  return;

        grid[i][j] = '0';

        dfs(i+1, j);
        dfs(i, j + 1);
        dfs(i - 1, j);
        dfs(i, j - 1);

    }
}
