class Solution {
    private final int[][] directions = {{1,0},{-1,0},{0,1},{0,-1}};
    private int m,n;
    public int countSubIslands(int[][] grid1, int[][] grid2) {
        m = grid1.length;
        n = grid1[0].length;

        int res = 0;
        boolean[][] visited = new boolean[m][n];

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid2[i][j] == 1 && !visited[i][j] && dfs(i,j,grid1,grid2,visited)){
                        res++;
                    
                }
            }
        }

        return res;
    }

    private boolean bfs(int i, int j, int[][] grid1,int[][] grid2,boolean[][] visited){
        Queue<int[]> q = new ArrayDeque<>();
        q.offer(new int[]{i,j});

        visited[i][j] = true;
        boolean res = true;

        while(!q.isEmpty()){
            int[] cell = q.poll();
            int r = cell[0], c = cell[1];
            if(grid1[r][c] == 0){
                res = false;
            }

            for(int[] dir : directions){
                int nr = r + dir[0], nc = c + dir[1];
                if(nr >= 0 && nc >= 0 && nr < m && nc < n && grid2[nr][nc] == 1 && !visited[nr][nc]){
                    q.offer(new int[]{nr,nc});
                    visited[nr][nc] = true;
                }
            }
        }

        return res;
    }

    private boolean dfs(int r, int c, int[][] grid1, int[][] grid2, boolean[][] visited) {
        if (r < 0 || c < 0 || r >= m || c >= n ||
            grid2[r][c] == 0 || visited[r][c]) {
            return true;
        }
        visited[r][c] = true;
        boolean res = grid1[r][c] == 1;
        res &= dfs(r - 1, c, grid1, grid2, visited);
        res &= dfs(r + 1, c, grid1, grid2, visited);
        res &= dfs(r, c - 1, grid1, grid2, visited);
        res &= dfs(r, c + 1, grid1, grid2, visited);
        return res;
    }
}