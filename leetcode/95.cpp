/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:


    vector<TreeNode *> buildTree(int s, int e){
        vector<TreeNode *> res;
        if(s > e) {
            res.push_back(nullptr);
            return res;
        }

        for(int i = s; i <= e; i++){
            auto leftTreeNode = buildTree(s, i-1);
            auto rightTreeNode = buildTree(i+1, e);
            for(auto l : leftTreeNode){
                for(auto r : rightTreeNode){
                    TreeNode *node = new TreeNode();
                    node->val = i;
                    node->left = l;
                    node->right = r;
                    res.push_back(node);
                }
            }
        }
        
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        auto ret = buildTree(1, n);
        return ret;
    }
};
