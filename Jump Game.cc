class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() < 1) return false;
        vector<int> dp(nums.size());
        int reach = 0;
        for (int i = 0; i <= reach && i < nums.size(); ++i){
            reach  = max(nums[i]+i, reach);
        }
        if (reach < nums.size()-1){
            return false;
        }
        return true;
    }
};