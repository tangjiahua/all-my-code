class MinStack {
    stack<int> myStack;
    stack<int> minStack;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        if(minStack.empty() || x <= minStack.top()){
            minStack.push(x);
        }
        myStack.push(x);
    }
    
    void pop() {
        if(!myStack.empty()){
            if(minStack.top() == myStack.top()){
                minStack.pop();
            }
            myStack.pop();
        }
    }
    
    int top() {
        return myStack.top();
    }
    
    int min() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
