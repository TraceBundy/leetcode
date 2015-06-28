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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> num;
        dfs(res, num, root, sum);
        return res;
    }
    void dfs(vector<vector<int>> &res, vector<int> &num, TreeNode *root, int sum){
        if (!root) return ;
        num.push_back(root->val);
        if (!root->left && !root->right) {
            if (sum == sumVec(num)){
                res.push_back(num);
            }
        }
        if (root->left) dfs(res, num, root->left, sum);
        if (root->right) dfs(res, num, root->right, sum);
        num.pop_back();
    }
    int sumVec(vector<int> &num){
        int sum = 0;
        for (int i = 0; i < num.size(); ++i){
            sum += num[i];
        }
        return sum;
    }
};