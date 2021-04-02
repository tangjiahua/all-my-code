class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int max = nums[0];
        int pre = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if (pre < 0){
                // 不选pre的
                pre = nums[i];
                if(nums[i] > max){
                    max = nums[i];
                }
                
            } else {
                // 选pre的
                int now = pre + nums[i];
                if(now >= 0){
                    // 选now的
                    if(now > max) max = now;
                    pre = now;
                } else {
                    // 不选now的
                    pre = nums[i];
                }
            }
        }
        return max;
    }
};
