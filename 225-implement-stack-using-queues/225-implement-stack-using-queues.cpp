/*
Steps:
- Insert in Q1
- Push remaining ele of Q2 in Q1
- Swap Q1 & Q2
*/
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    void push(int x) {
        q1.push(x);
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        swap(q1, q2);
    }
    
    int pop() {
        int ans;
        if(q2.empty()) {
            ans= -1;
        }
        else {
            ans= q2.front();
            q2.pop();
        }
        return ans;
    }
    
    int top() {
        return q2.front();
    }
    
    bool empty() {
        return q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */