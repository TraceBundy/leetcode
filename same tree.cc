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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool status = true;
        dfs(p, q, status);
        return status;
    }
    void dfs(TreeNode* p, TreeNode* q, bool &status){
        if (!status) return;
        if ((!p && q) || (p && !q)){
            status = false;
            return;
        } else if (!p && !q){
            return;
        }
        if (p->val == q->val){
            dfs(p->left, q->left, status);
            dfs(p->right, q->right, status);
        } else {
            status = false;
        }
    }
};