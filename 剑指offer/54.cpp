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
    int m = 0;
    int final = 0;
    int result = 0;
public:
    int kthLargest(TreeNode* root, int k) {
        final = k;
        dfs(root);
        return result;
    }

    void dfs(TreeNode* root){
        if(root == NULL) return;
        dfs(root->right);
        m++;
        if(m == final){
            result = root->val;
        }
        dfs(root->left);
    }
};
