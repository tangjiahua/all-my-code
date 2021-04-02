class Solution {
public:
    char firstUniqChar(string s) {
        if(s == " ") return ' ';
        unordered_map<char, int> map;
        int size = s.size();
        for(int i = 0; i < size; i++){
            map[s[i]]++;
        } 
        for(int i = 0; i < size; i++){
            if(map[s[i]] == 1) return s[i];
        } 
        return ' ';
    }
};
