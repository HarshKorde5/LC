class Solution {
    private int m,n,res,area;
    private boolean[][] visited;
    private static final int directions[][] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    public int maxAreaOfIsland(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        res = 0;
        area = 0;
        visited = new boolean[m][n];

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    dfs(i,j,grid);
                    res = res > area ? res : area;
                    area = 0;
                }
            }
        }

        return res;
        
    }

    private void dfs(int i, int j, int[][] grid){
        if(i < 0 || j < 0 || i >= m ||  j >= n || grid[i][j] == 0 || visited[i][j]) return;

        visited[i][j] = true;
        area += 1;
        for(int[] dir : directions){
            dfs(i + dir[0], j + dir[1], grid);
        }
    }


    private void bfs(int i, int j, int[][] grid){
        Deque<int[]> q = new ArrayDeque<>();

        q.offer(new int[]{i,j});
        visited[i][j] = true;
        area = 1;

        while(!q.isEmpty()){
            int[] curr = q.poll();

            int r  = curr[0], c = curr[1];

            for(int[] dir : directions){
                int nr = r + dir[0], nc = c + dir[1];

                if(nr < 0 || nc < 0 || nr >= m || nc >= n || grid[nr][nc] == 0 || visited[nr][nc])   continue;

                area++;
                visited[nr][nc] = true;
                q.add(new int[]{nr,nc});
            }
            
        }
    }
}
