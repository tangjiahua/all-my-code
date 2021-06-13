class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> myStack;
        int i = 0;
        for(auto p : pushed){
            myStack.push(p);
            while(!myStack.empty() && popped[i] == myStack.top()){
                myStack.pop();
                i++;
            }
        }
        return myStack.empty();
    }
};
