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
    vector<vector<int>> ret;
    vector<int> result;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, 0, sum);
        return ret;
    }
    void dfs(TreeNode* root, int temp, int sum){
        if(root == NULL) return;
        if(temp + root->val == sum && (root->left == NULL && root->right == NULL)){
            result.push_back(root->val);
            ret.push_back(result);
        }else{
            result.push_back(root->val);
            if(root->left){
                dfs(root->left, temp + root->val, sum);
            }
            if(root->right){
                dfs(root->right, temp + root->val, sum);
            }
        }
        result.pop_back();
    }
};
