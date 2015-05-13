class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        set <vector<int>> unique;
        vector<int> tmp;
        backtracking(result, unique, candidates, tmp, 0, 0, target);
        return result;
    }
    void backtracking(vector<vector<int>> &result, set<vector<int>> &unique, vector<int> &candidates, vector<int> &tmp, int sum, int k, int target){
        if (sum == target){
            if (unique.find(tmp) == unique.end()){
                unique.insert(tmp);
                result.push_back(tmp);
            }
            return;
        } else if (sum > target){
            return;
        }
        for (int i = k; i < candidates.size(); ++i){
            if (sum + candidates[i] <= target){
                sum += candidates[i];
                tmp.push_back(candidates[i]);
                backtracking(result, unique, candidates, tmp, sum, i+1, target);
                tmp.pop_back();
                sum -= candidates[i];
            }
        }
    }
};