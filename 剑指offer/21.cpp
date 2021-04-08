class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        while(i < j){
            while(nums[i] % 2 == 1 && i < j){
                i++;
            }
            while(nums[j] % 2 == 0 && i < j){
                j--;
            }
            if(i >= j) break;
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        };
        return nums;
    }
};
