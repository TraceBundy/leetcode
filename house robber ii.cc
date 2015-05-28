class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return nums[0] > nums[1] ? nums[0] : nums[1];
        vector<int> dp(n,0);
        vector<int> dp2(n+1,0);
        dp[0] = 0;
        dp[1] = nums[0];
        dp2[0] = 0;
        dp2[1] = 0;
        dp2[2] = nums[1];
        for (int i = 2; i < n; ++i){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
        }
        for (int i = 3; i <= n; ++i){
            dp2[i] = max(dp2[i-1], dp2[i-2]+nums[i-1]);
        }
        return dp[n-1] > dp2[n] ? dp[n-1] : dp2[n];
    }
};