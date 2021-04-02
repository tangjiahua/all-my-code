class Solution {
public:

    void swap(vector<int>& nums ,int i ,int j){
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }

    void sortColors(vector<int>& nums) {


        int p0 = -1, p1 = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                swap(nums, p1+1, i);
                swap(nums, p1+1, p0+1);
                p0++;
                p1++;
            } else if(nums[i] == 1){
                swap(nums, p1+1, i);
                p1++;
            }
        }
        
    }
};
