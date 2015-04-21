class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<int> sub;
        vector<vector<int> > result;
        sort(candidates.begin(), candidates.end());
        int pos = 0;
        dfs(target, pos, sub, candidates, result);
        return result;
    }
    void dfs(int target, int pos, vector<int> &sub, vector<int> &candidates, vector<vector<int> > &result){
        if (target == 0){
            result.push_back(sub);
            return;
        }
        if (target < 0) return;
        if (target - candidates[pos] >= 0){
            sub.push_back(candidates[pos]);
            dfs(target-candidates[pos], pos, sub, candidates, result);
            sub.pop_back();
        }
        for (int i = pos+1; i < candidates.size(); ++i){
            sub.push_back(candidates[i]);
            dfs(target-candidates[i], i, sub, candidates, result);
            sub.pop_back();
        }
    }
};