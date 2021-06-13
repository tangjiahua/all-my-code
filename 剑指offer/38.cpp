class Solution {
public:
    vector<string> permutation(string s) {
        unordered_set<string> res;
        backtrack(s, res, 0);
        return vector<string>(res.begin(), res.end());
    }

    void backtrack(string s, unordered_set<string> &res, int start){
        if(start == s.size()){
            res.insert(s);
            return;
        }
        for(int i = start; i < s.size(); i++){
            swap(s[i], s[start]);
            backtrack(s, res, start+1);
            swap(s[i], s[start]);
        }
    }
};
