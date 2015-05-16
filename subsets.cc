class Solution {
public:
    vector<vector<int> > subsets(vector<int> &nums) {
        vector<vector<int> > result;
        vector<int> tmp;
        if(nums.size() ==0) return result;
        result.push_back(tmp);
        sort(nums.begin(), nums.end());
        backtracking( result, nums,tmp, 0);
    }
    void backtracking(vector<vector<int> > &result, vector<int> &nums,  vector<int>& tmp , int k)  {
        for(int i = k;i<nums.size(); i++ ){
            tmp.push_back(nums[i]);
            result.push_back(tmp);
            if(i< nums.size()-1)
                backtracking( result,nums, tmp, i+1);
            tmp.pop_back();
        }
    }
};
