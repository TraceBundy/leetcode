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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(sum, 0, root);
        return sum;
    }
    void dfs(int &sum, int cur, TreeNode* root){
        if (!root) return;
        cur = cur*10 + root->val;
        if (!root->left && !root->right){
            sum += cur;
            return;
        }
        dfs(sum, cur, root->left);
        dfs(sum, cur, root->right);
    }
};