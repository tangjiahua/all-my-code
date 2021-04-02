struct Node{
    char x;
    int y;
    Node(char x, int y):x(x), y(y){}
    bool operator<(const Node b) const{
        return y < b.y;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(auto it : s){
            mp[it]++;
        }

        priority_queue<Node, vector<Node>> q;
        for(auto it : mp){
            q.push(Node(it.first, it.second));
        }

        string ret;
        while(!q.empty()){
            for(int i = 0; i < q.top().y; i++){
                ret += q.top().x;
            }
            q.pop();
        }
        return ret;
    }
};
