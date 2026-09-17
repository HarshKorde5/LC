class Solution {
    private char[][] grid;
    private boolean[][] visited;
    private int m, n, res;
    private static final int[][] directions = {{1,0}, {0, 1}, {-1,0}, {0,-1}};

    public int numIslands(char[][] grid) {
        this.grid = grid;
        this.m = grid.length;
        this.n = grid[0].length;
        this.visited = new boolean[m][n];
        this.res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    bfs(i, j);
                    res++;
                }
            }
        }

        return res;
    }

    private void dfs(int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0' || visited[i][j])
            return;

        visited[i][j] = true;

        dfs(i + 1, j);
        dfs(i, j + 1);
        dfs(i - 1, j);
        dfs(i, j - 1);

    }

    private void bfs(int i, int j) {
        Deque<int[]> q = new ArrayDeque<>();
        visited[i][j] = true;
        q.offer(new int[] { i, j });

        while (!q.isEmpty()) {
            int[] node = q.poll();
            int row = node[0], col = node[1];

            for (int[] dir : directions) {
                int newRow = row + dir[0], newCol = col + dir[1];

                if (newRow >= 0 && newCol >= 0 && newRow < m && newCol < n && grid[newRow][newCol] == '1'
                        && !visited[newRow][newCol]) {
                    visited[newRow][newCol] = true;
                    q.add(new int[] { newRow, newCol });
                }
            }
        }
    }
}
