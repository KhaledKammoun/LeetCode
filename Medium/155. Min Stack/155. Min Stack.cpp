class MinStack {
public:
    MinStack() {
        Stack = new stack<int>();
    }
    
    void push(int val) {
        Stack->push(val) ;
        if (minStack.empty() || minStack.top()>=val)
            minStack.push(val) ;
    }
    
    void pop() {
        if (Stack->top()==minStack.top())
            minStack.pop() ;
        Stack->pop() ;
    }
    int top() {
        return Stack->top() ;
    }
    
    int getMin() {
        return minStack.top() ;
    }
    private :
        stack<int>*Stack;
        stack<int>minStack ;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */