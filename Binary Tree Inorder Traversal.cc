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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(result, root);
        return result;
    }
    void inorder(vector<int> &res, TreeNode *node){
        if (!node) return;
        inorder(res, node->left);
        res.push_back(node->val);
        inorder(res, node->right);
    }
};