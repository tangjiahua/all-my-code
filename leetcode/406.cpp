class Solution {
public:

    static bool cmp(const vector<int>& u, const vector<int>& v) {
            return u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]);
        }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> ret;
        for(auto it : people){
            if(it[1] >= ret.size()){
                ret.push_back(it);
            } else {
                ret.insert(ret.begin() + it[1], it);
            }
        }

        
        return ret;
    }
};
