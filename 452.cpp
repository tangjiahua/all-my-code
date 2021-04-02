class Solution {
public:

    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        // 排序
        if(points.size() == 0) return 0;
        sort(points.begin(), points.end(), cmp);

        // 遍历，
        int i = 0, ret = 0;
        while(i < points.size()){
            ret++;
            int arrow = points[i][1];
            int j = i + 1;
            while(j < points.size()){
                if(points[j][0] <= arrow && points[j][1] >= arrow){
                    j++;
                } else {
                    break;
                }
            }
            i = j;
        }
        return ret;
    }
};
