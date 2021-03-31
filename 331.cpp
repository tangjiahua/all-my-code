class Solution {
public:
    bool isValidSerialization(string preorder) {
        
        vector<char> nodes;
        int index;
        bool last_is_number = false;
        for(int i = 0; i < preorder.size(); i++){
            if(preorder[i] == ',') continue;
            if(i < preorder.size() - 1 && preorder[i+1] >= '0' && preorder[i+1] <= '9'){
                continue;
            }

            nodes.push_back(preorder[i]);
            index = nodes.size();
            while(nodes.size() >= 3 && nodes[index - 1] == '#' && nodes[index - 2] == '#' && nodes[index - 3] != '#'){
                nodes.pop_back();
                nodes.pop_back();
                nodes.pop_back();
                nodes.push_back('#');
                index = nodes.size();
            }
        }
        return nodes.size() == 1 && nodes[0] == '#';
    }
};
