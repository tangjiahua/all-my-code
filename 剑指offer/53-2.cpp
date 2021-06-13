class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0, j = nums.size();
        while(i < j){
            int k = (i+j)/2;
            if(nums[k] == k){
                i = k + 1;
            }else{
                j = k;
            }
        }
        return i;
    }
};
