class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> unique;
        vector<int> tmp;
        if(nums.size() ==0) return result;
        result.push_back(tmp);
        sort(nums.begin(), nums.end());
        backtracking( result, unique, nums,tmp, 0);
    }
    void backtracking(vector<vector<int> > &result, set<vector<int>> &unique, vector<int> &nums,  vector<int>& tmp , int k)  {
        for(int i = k;i<nums.size(); i++ ){
            tmp.push_back(nums[i]);
            if (unique.find(tmp) == unique.end()){
                unique.insert(tmp);
                result.push_back(tmp);
            }
            if(i< nums.size()-1)
                backtracking( result, unique, nums, tmp, i+1);
            tmp.pop_back();
        }
    }
};