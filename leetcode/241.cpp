class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for(int i = 0; i < input.size(); i++){
            if(input[i] == '+' || input[i] == '-' || input[i] == '*'){
                vector<int> leftRes = diffWaysToCompute(input.substr(0, i));
                vector<int> rightRes = diffWaysToCompute(input.substr(i+1));

                for(int l : leftRes){
                    for(int r : rightRes){
                        if (input[i] == '+'){
                            res.push_back(l + r);
                        } else if(input[i] == '-'){
                            res.push_back(l - r);
                        } else {
                            res.push_back(l * r);
                        }
                        
                    }
                }
                //return res;
            }
        }
        if (res.size() == 0) {
            res.push_back(atoi(input.c_str()));
        }
        
        return res;
    }
};
