class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       vector<int> tmp(nums.size(), 0);
       vector<vector<int> > result;
       vector<int> status(nums.size(), 0);
       sort(nums.begin(), nums.end());
       backtracking(result, nums, tmp, status, 0);
       return result;
    }
    void backtracking(vector<vector<int> > &result, vector<int> &num, vector<int> &tmp, vector<int> status, int k){
        if (k == num.size()){
            result.push_back(tmp);
            return;
        }
        for (int i = 0; i < num.size(); ++i){
            if (status[i]) continue;
            if (i > 0 && num[i] == num[i-1] && status[i-1]) continue;
            tmp[k] = num[i];
            status[i] = 1;
            backtracking(result, num, tmp, status, k+1);
            status[i] = 0;
        }
    }
};
SET SESSION max_statement_time =