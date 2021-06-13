/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    vector<Node*> result;
    Node* treeToDoublyList(Node* root) {
        if(root == NULL) return NULL;
        dfs(root->left);
        result.push_back(root);
        dfs(root->right);

        if(result.size() == 1){
            result[0]->left = result[0];
            result[0]->right = result[0];
            return result[0];
        }

        result[0]->left = result[result.size()-1];
        result[0]->right = result[1];
        result[result.size()-1]->left = result[result.size()-2];
        result[result.size()-1]->right = result[0];
        for(int i = 1; i < result.size()-1; i++){
            result[i]->left = result[i-1];
            result[i]->right = result[i+1];
        }
        return result[0];
    }
    void dfs(Node* root){
        if(root == NULL) return;
        dfs(root->left);
        result.push_back(root);
        dfs(root->right);
    }
};
