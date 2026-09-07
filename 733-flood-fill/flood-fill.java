class Solution {
    public int[][] floodFill_bfs(int[][] image, int sr, int sc, int color) {
        int orig = image[sr][sc];
        if(orig == color)   return image;

        int m = image.length, n = image[0].length;

        Deque<int[]> q = new ArrayDeque<>();
        q.add(new int[]{sr, sc});
        image[sr][sc] = color;
        
        int[][] dirs = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};

        while(!q.isEmpty()){
            int[] cell = q.remove();

            int r = cell[0], c = cell[1];
            for(int[] d : dirs){
                int nr = r + d[0], nc = c + d[1];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && image[nr][nc] == orig){
                    image[nr][nc] = color;
                    q.add(new int[]{nr, nc});
                }
            }
        }

        return image;
    }

    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int orig = image[sr][sc];
        if(orig == color)   return image;

        int m = image.length, n = image[0].length;

        dfs(image, sr, sc, orig, color, m, n);
        return image;
    }

    private void dfs(int[][] image, int r, int c, int orig, int color, int m, int n){
        if(r < 0 || r >= m || c < 0 || c >= n || image[r][c] != orig)   return;

        image[r][c]  = color;
        dfs(image, r - 1, c, orig, color, m, n);
        dfs(image, r, c + 1, orig, color, m, n);
        dfs(image, r + 1, c, orig, color, m, n);
        dfs(image, r , c - 1, orig, color, m, n);
    }
}