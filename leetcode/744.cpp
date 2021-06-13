class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ret = letters[0];
    
        int i = 0, j = letters.size() - 1;
        int index = letters.size();

        while(i <= j){
            int mid = i + (j - i)/2;
            if (letters[mid] > target){
                j = mid - 1;
                ret = letters[mid];
            } else {
                i = mid + 1;
            }   
        }

        return ret;
    }
};
