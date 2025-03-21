
/*

Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
*/



class MyStack {

    public:
    queue<int>q1;
   
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
       for(int i=0;i<q1.size()-1;i++){
            q1.push(q1.front());
            q1.pop();
        }
        
    }
    
    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }


// private:

//     queue<int> q1;
//     queue<int> q2;

//     MyStack() {
        
//     }
    
//     void push(int x) {
//         q1.push(x);
//     }
    
//     int pop() {
//         int x = q1.back();


//         while(!q1.empty())
//         {
//             if(q1.front() == q1.back())
//             {
//                 q1.pop();
//             }
//             else
//             {
//                 q2.push(q1.front());
//                 q1.pop();
//             }
//         }

//         while(!q2.empty())
//         {
//             q1.push(q2.front());
//             q2.pop();
//         }

//         return x;
//     }
    
//     int top() {
//         return q1.back();
//     }
    
//     bool empty() {
//         return q1.empty();
//     }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


 int main()
 {
    return 0;
 }