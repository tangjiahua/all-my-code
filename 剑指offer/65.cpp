class Solution {
public:
    int add(int a, int b) {
         int sum = 0;
         int carry = 0;
         while(b != 0){
             sum = a ^ b;
             carry = (unsigned int)(a & b) << 1;
             a = sum;
             b = carry;
         }
         return a;
    }
};
