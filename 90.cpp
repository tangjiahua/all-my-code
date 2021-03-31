class Solution {
public:

    vector<int> res;
    vector<vector<int>> ret;

void find(int index, int lastNum, bool lastNumChosen, vector<int>& nums){
    bool flag = false;
    if (nums[index] == lastNum && lastNumChosen) {
        flag = true;
    }
    if (index == nums.size() - 1){
        if(!flag){
            ret.push_back(res);
        }

        res.push_back(nums[index]);
        ret.push_back(res);
    } else {
        if(!flag){
            find(index + 1, nums[index], false, nums);
        }

        res.push_back(nums[index]);
        
        find(index + 1, nums[index], true, nums);
    }
    res.pop_back();
}

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        find(0, -11, false, nums);
        return ret;
    }
};
