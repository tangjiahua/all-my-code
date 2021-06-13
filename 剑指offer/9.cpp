class CQueue {
    stack<int> stack1,stack2;
public:
    CQueue() {
    }
    
    void appendTail(int value) {
        stack1.push(value);
    }
    
    int deleteHead() {
        if(!stack2.empty()){
            int val = stack2.top();
            stack2.pop();
            return val;
        }else{
            if(stack1.empty()){
                return -1;
            }
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
            int val = stack2.top();
            stack2.pop();
            return val;
        }
    }
};
