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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || preorder.size() != inorder.size()) return NULL;
        int a = 0, b = preorder.size()-1, c = 0, d = inorder.size()-1;
        return binaryTree(preorder, inorder, a, b, c, d);
    }

    TreeNode* binaryTree(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd){
        if(preStart > preEnd || inStart > inEnd) return NULL;
        TreeNode *root = new TreeNode(preorder[preStart]);
        int div = 0;
        for(auto i : inorder){
            if(i != preorder[preStart]) div++;
            else break;
        }
        root->left = binaryTree(preorder, inorder, preStart+1, preStart + (div - inStart), inStart, div-1);
        root->right = binaryTree(preorder, inorder, preStart + (div - inStart) + 1, preEnd, div+1, inEnd);
        return root;
    }
};
