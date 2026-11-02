class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        queue<int> q;
        vector<int> min_rolls(n*n+1, -1);

        min_rolls[1] = 0;
        q.push(1);


        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(int i = 1; i <= 6 && curr + i <= n*n; i++){
                int next = curr + i;
                int r = (next - 1) / n, c = (next - 1) % n;

                int nextSquare = board[n - 1 - r][r % 2 ? n - 1 - c: c];
                int value = nextSquare > 0 ? nextSquare : next;

                if(value == n*n){
                    return min_rolls[curr] + 1;
                }

                if(min_rolls[value] == -1){
                    min_rolls[value] = min_rolls[curr] + 1;
                    q.push(value);
                }
            }
        }


        return -1;
    }
};