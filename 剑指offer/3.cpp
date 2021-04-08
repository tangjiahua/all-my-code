class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        //* 遍历放进Set中,利用集合的特性(唯一性)进行解决
        //* 如果放不进去,那么就说明该元素重复
        unordered_set<int> myset;
        for (size_t i = 0; i < nums.size(); i++) {
            if(!myset.insert(nums[i]).second)
            {
                return nums[i];
            }
        }
        return -1;
    }
};
