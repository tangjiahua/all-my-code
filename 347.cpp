struct Node{
    int x, y;
    Node(int x, int y):x(x), y(y){}
    bool operator<(Node const &b) const{
        return y > b.y; 
    }
};

class Solution {
public:
    static bool cmp(pair<int, int>& m, pair<int, int>& n) {
            return m.second > n.second;
        }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto num : nums){
            mp[num]++;
        }
        //priority_queue<Node, vector<Node>> q;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        //priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        //priority_queue<pair<int, int>, vector<pair<int, int>> greater<int>> q;
        for(auto it : mp){
            if(q.size() != k){
                q.push(make_pair(it.first, it.second));
            } else {
                if(q.top().second < it.second){
                    q.pop();
                    q.push(make_pair(it.first, it.second));
                }
            }
            
        }
        vector<int> ret;
        while(!q.empty()){
            ret.push_back(q.top().first);
            q.pop();
        }
        return ret;
    }
};
