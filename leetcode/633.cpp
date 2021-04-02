class Solution {
public:
    bool judgeSquareSum(int c) {

        int index1 = 0, index2 = (int)sqrt(c);
        while(index1 <= index2){
            if(index1*index1 == c - index2*index2){
                return true;
            } else if(index1*index1 > c - index2*index2){
                index2--;
            } else {
                index1++;
            }
        }
        return false;
    }
};
