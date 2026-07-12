class MyStack1 {

    private Queue<Integer> A;
    private Queue<Integer> B;

    public MyStack1() {
        A = new LinkedList<>();
        B = new LinkedList<>();
    }
    
    public void push(int x) {
        B.offer(x);

        while(!A.isEmpty()){
            B.offer(A.poll());
        }

        Queue<Integer> tmp = A;
        A = B;
        B = tmp;
    }
    
    public int pop() {
        return A.poll();
    }
    
    public int top() {
        return A.peek();
    }
    
    public boolean empty() {
        return A.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */

 class MyStack {
    private Queue<Integer> q;

    public MyStack() {
        q = new LinkedList<>();
    }
    
    public void push(int x) {
        q.offer(x);

        for(int i = 0; i < q.size() - 1; i++){
            q.offer(q.poll());
        }
    }
    
    public int pop() {
        return q.poll();
    }
    
    public int top() {
        return q.peek();
    }
    
    public boolean empty() {
        return q.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */