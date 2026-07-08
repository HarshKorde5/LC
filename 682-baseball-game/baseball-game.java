class Solution {
    public int calPoints(String[] operations) {
        Deque<Integer> scoreBoard = new ArrayDeque<>();
        int finalScore = 0;

        for(String op : operations){
            if(op.equals("C")){
                int score = scoreBoard.pop();
                finalScore -= score;
            }else if(op.equals("D")){
                int lastScore = scoreBoard.peek();
                int newScore = lastScore*2;
                scoreBoard.push(newScore);
                finalScore += newScore;
            }else if(op.equals("+")){
                int a = scoreBoard.pop();
                int b = scoreBoard.pop();

                int newScore = a + b;
                scoreBoard.push(b);
                scoreBoard.push(a);
                scoreBoard.push(newScore);
                finalScore += newScore;
            }else{
                int newScore = Integer.parseInt(op);
                scoreBoard.push(newScore);
                finalScore += newScore;
            }

            System.out.println(scoreBoard);
        }

        return finalScore;
    }
}