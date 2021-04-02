class Solution {
public:
    
    bool isIt(char ch){
        switch(ch){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                return true;
        }
        return false;
    }

    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        string ret;
        while(i < j){
            while(!isIt(s[i]) && i < j){
                i++;
                continue;
            }

            while(!isIt(s[j]) && i < j){
                j--;
                continue;
            }

            // i j means it
            if(i != j){
                int temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                i++;
                j--;
            }
        }
        return s;
    }
};
