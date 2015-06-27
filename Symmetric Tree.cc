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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return dfs(root->left, root->right);
    }
    bool dfs(TreeNode *left, TreeNode *right){
        if (!left) return right == NULL;
        if (!right) return left == NULL;
        if (left->val != right->val) return false;
        if (!dfs(left->left, right->right))
            return false;
        if (!dfs(left->right, right->left))
            return false;
        return true;
    }
};