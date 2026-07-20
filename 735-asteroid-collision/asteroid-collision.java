class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Deque<Integer> stack = new ArrayDeque<>();

       
        for(int a : asteroids){
            while(!stack.isEmpty() && a < 0 && stack.peek() > 0){
                int diff = a + stack.peek();

                if(diff > 0){
                    a = 0;
                }else if(diff < 0){
                    stack.pop();
                }else{
                    a = 0;
                    stack.pop();
                }
            }

            if(a != 0){
                stack.push(a);
            }
        }

        int[] res = new int[stack.size()];
        int idx = stack.size() - 1;
        while(!stack.isEmpty()){
            res[idx--] = stack.pop();
        }

        return res;
    }
}