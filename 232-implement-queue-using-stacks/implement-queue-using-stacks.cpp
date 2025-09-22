class MyQueue {
    stack<int>st1;
    stack<int>st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(st2.empty()){
            int sz1 = st1.size();
            while(sz1--){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int front_ele = st2.top();
        st2.pop();
        return front_ele;
    }
    
    int peek() {
        if(st2.empty()){
            int sz1 = st1.size();
            while(sz1--){
                st2.push(st1.top());
                st1.pop();
            }
        };
        return st2.top();
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */