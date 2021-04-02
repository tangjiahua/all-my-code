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
        vector<vector<int>> result;
        if(root == NULL) return result;

        
        bool flag = true;
        deque<TreeNode*> q;
        q.push_back(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            while(n > 0){    
                TreeNode *node;  
                if(flag){
                    node = q.front();
                    q.pop_front();
                    temp.push_back(node->val);
                    if(node->left) q.push_back(node->left);
                    if(node->right) q.push_back(node->right);
                }else{
                    node = q.back();
                    q.pop_back();
                    temp.push_back(node->val);
                    if(node->right) q.push_front(node->right);
                    if(node->left) q.push_front(node->left);
                }
                n--;
            }
            result.push_back(temp);
            flag = !flag;
        }
        return result;
    }
};
