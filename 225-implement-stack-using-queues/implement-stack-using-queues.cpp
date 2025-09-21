class MyStack {
    queue<int>q;
    int top_element;
public:
    MyStack() {
        top_element = -1;
    }
    
    void push(int x) {
        q.push(x);
        top_element = x;
    }
    
    int pop() {
        int sz = q.size();
        while(--sz){
            top_element = q.front();
            q.push(q.front());
            q.pop();
        }
        int popped_value = q.front();
        q.pop();
        return popped_value;
    }
    
    int top() {
        return top_element;
    }
    
    bool empty() {
        return q.size()==0;
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