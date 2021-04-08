class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        vector<int> result = vector<int>();
        do{
            int temp = nums[i] + nums[j];
            if(temp == target){
                result.push_back(nums[i]);
                result.push_back(nums[j]);
                return result;
            }else{
                if(temp > target){
                    j--;
                }else{
                    i++;
                }
            }
        }while(1);
        return result;
    }
};
