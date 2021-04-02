class Solution {
public:

    bool isMatch(string s, string d){
        int i = 0, j = 0;
        int slen = s.size(), dlen = d.size();
        while(i < slen && j < dlen){
            if(s[i] == d[j]){
                i++;
                j++;
            } else {
                i++;
            }
        }

        if(j < dlen) return false;
        return true;
    }

    string findLongestWord(string s, vector<string>& d) {
        int maxLen = 0;
        string ret;
        sort(d.begin(), d.end());
        for(int i = 0; i < d.size(); i++){
            if(isMatch(s, d[i])){
                if(d[i].size() > maxLen){
                    maxLen = d[i].size();
                    ret = d[i];
                }
            }
        }
        return ret;
    }
};
