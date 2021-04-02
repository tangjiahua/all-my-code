class Solution {
public:

    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int ret = 0;
        if(intervals.size() <= 1){
            return ret;
        }

        int right = intervals[0][1];
        ret = 1;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] >= right){
                ret++;
                right = intervals[i][1];
            }
        }

        return intervals.size() - ret;

    }
};
