class Solution {
    int ROWS, COLS;
    boolean[][] visited;

    public boolean exist(char[][] board, String word) {
        ROWS = board.length;
        COLS = board[0].length;
        visited = new boolean[ROWS][COLS];

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                boolean res = dfs(board, word, r, c, 0);
                if (res == true)
                    return true;
            }
        }

        return false;
    }

    private boolean dfs(char[][] board, String word, int r, int c, int idx) {
        if (idx == word.length())
            return true;

        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || word.charAt(idx) != board[r][c] || visited[r][c])
            return false;

        visited[r][c] = true;

        boolean res = dfs(board, word, r - 1, c, idx + 1) ||
                dfs(board, word, r, c + 1, idx + 1) ||
                dfs(board, word, r + 1, c, idx + 1) ||
                dfs(board, word, r, c - 1, idx + 1);

        visited[r][c] = false;

        return res;
    }
}
