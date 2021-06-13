class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool flag = false;
        int temp = nums[0];

        for(int i = 0; i < nums.size(); i++){
            if (nums[i] >= temp){
                temp = nums[i];
            } else {
                if (flag == true) return false;
                int pre = i-2;
                if (i-2 < 0){
                    temp = nums[i];
                } else {
                    if (nums[pre] <= nums[i]){
                        temp = nums[i];
                    } else {
                        temp = nums[i-1];
                    }
                }
                flag = true;
            }
        }
        return true;
    }
};
