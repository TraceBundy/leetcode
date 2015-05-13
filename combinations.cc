class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> num;
        for (int i = 1; i <=n; ++i){
            num.push_back(i);
        }
        vector<vector<int>> result;
        vector<int> tmp;
        backtracking(result, num, tmp, k, 0);
        return result;
    }
    void backtracking(vector<vector<int>> &result, vector<int> &num, vector<int> &tmp, int k, int pos)
    {
        if (tmp.size() == k){
            result.push_back(tmp);
            return;
        }
        for (int i = pos; i < num.size(); ++i){
            tmp.push_back(num[i]);
            backtracking(result, num, tmp, k, i+1);
            tmp.pop_back();
        }
    }
};