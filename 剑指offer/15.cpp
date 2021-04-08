class Solution {
public:
    int count = 0;
    int hammingWeight(uint32_t n) {
        while(n/2 != 0){
            if(n%2 == 1){
                count++;
            }
            n = n/2;
        }
        if(n == 1) count++;
        return count;
    }
};
