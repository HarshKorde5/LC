class Solution {
    public int snakesAndLadders(int[][] board) {
        int n = board.length;

        int[] dist = new int[n*n+1];
        Arrays.fill(dist, -1);

        dist[1] = 0;

        Deque<Integer> q = new ArrayDeque<>();

        q.offer(1);

        while(!q.isEmpty()){
            int curr = q.poll();

            if(curr == n*n){
                return dist[curr];
            }

            for(int move = curr + 1; move <= Math.min(curr+6, n*n); move++){
                int layer = (move - 1) / n; //from bottom-up
                int row = n - 1 - layer; //from top-down
                int col = (move - 1) % n;   

                if(layer % 2 == 1){
                    col = n - 1 - col;
                }

                int target = board[row][col] == -1 ? move : board[row][col];

                if(dist[target] == -1){
                    dist[target] = dist[curr] + 1;
                    q.offer(target);
                }
            }

        }

        return -1;
    }
}