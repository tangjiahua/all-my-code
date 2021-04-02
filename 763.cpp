class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ret;
        vector<vector<int>> res;
        map<char, int> mp;
        for(int i = 0; i < S.size(); i++){
            mp[S[i]] = i;
        }
        int start = 0, end = 0;
        for(int i = 0; i < S.size(); i++){
            if (i == start){
                end = mp[S[start]];
            }
            if (i == end){
                ret.push_back(end - start + 1);
                start = i+1;

            } else {
                end = max(end, mp[S[i]]);
            }
        }
        return ret;
    }
};
