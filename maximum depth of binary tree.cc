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
    int maxDepth(TreeNode* root) {
        int max = 0;
        dfs(root, max, 1);
        return max;
    }
    void dfs(TreeNode *root, int &max, int k){
        if (!root) return;
        max = max > k ? max : k;
        if (root->left){
            dfs(root->left, max, k+1);
        }
        if (root->right){
            dfs(root->right, max, k+1);
        }
    }
};