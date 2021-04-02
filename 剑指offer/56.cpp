class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++){
            result = result ^ nums[i];
        }
        int div = 1;
        while((result & div) == 0){
            div <<= 1;
        }
        int a = 0, b = 0;
        for(int num : nums){
            if((num & div) == 0){
                a ^= num;
            }else{
                b ^= num;
            }
        }
        return vector<int>{a, b};
    }
};
