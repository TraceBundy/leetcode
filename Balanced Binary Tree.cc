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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        bool res = true;
        dfs(root, res);
        return res;
    }
    int dfs(TreeNode* root, bool &res){
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        bool leftBalance = true;
        bool rightBalance = true;
        int left = dfs(root->left, leftBalance);
        int right = dfs(root->right, rightBalance);
        res = leftBalance && rightBalance;
        if (abs(left - right) > 1) res = false;
        return (max(left, right) +1);
    }
};