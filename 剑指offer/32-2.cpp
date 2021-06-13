/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> result;
        while(q.size()){
            int size = q.size();
            vector<int> temp;
            for(int i = 0; i < size; i++){
                TreeNode *t = q.front();
                q.pop();
                if(!t) continue;
                temp.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            if(temp.size() != NULL) result.push_back(temp);
        }
        return result;
    }
};
