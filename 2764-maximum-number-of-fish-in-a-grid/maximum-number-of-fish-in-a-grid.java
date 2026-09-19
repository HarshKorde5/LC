class Solution {
    private int[][] directions = {{-1,0},{0,1},{1,0},{0,-1}};
    private int m, n;
    public int findMaxFish(int[][] grid) {
        this.m = grid.length;
        this.n = grid[0].length;
        int res = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] > 0){
                    int fish = dfs(i,j,grid);
                    res = res > fish ? res : fish;
                }
            }
        }

        return res;
    }

    private int dfs(int r, int c, int[][] grid){
        if(r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0)   return 0;

        int fish = grid[r][c];
        grid[r][c] = 0;
        
        for(int[] dir : directions){
            int nr = r + dir[0], nc = c + dir[1];
            fish += dfs(nr, nc, grid);
        }
        return fish;
    }
}