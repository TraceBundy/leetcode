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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> num;
        postorder(num, root);
        return num;
    }
    void postorder(vector<int> &num, TreeNode *root){
        if (!root) return;
        postorder(num, root->left);
        postorder(num, root->right);
        num.push_back(root->val);
    }
};