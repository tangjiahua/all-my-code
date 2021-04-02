/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include <queue>
class Solution {
public:
    int sum = 0;
    queue<TreeNode*> q;

    bool isLeaf(TreeNode *root){
        return !root->left && !root->right;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        q.push(root);
        while(!q.empty()){
            TreeNode * node = q.front();
            q.pop();
            if(node->left != NULL){
                if(isLeaf(node->left)){
                    sum += node->left->val;
                } else {
                    q.push(node->left);
                }
                
            }
            if(node->right != NULL){
                q.push(node->right);
            }

        }
        return sum;
    }
};
