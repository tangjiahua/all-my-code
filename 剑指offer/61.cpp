class Solution {
public:
    bool isStraight(vector<int>& nums) {
        bool map[15];
        memset(map, 0, sizeof(map));
        int minValue = 13, maxValue = 0;
        for(int i = 0; i < 5; i++){
            if(map[nums[i]]) return false;
            if(nums[i] == 0) continue;
            minValue = min(minValue, nums[i]);
            maxValue = max(maxValue, nums[i]);
            map[nums[i]] = true;
        }
        return (maxValue-minValue <= 4);
    }
};
