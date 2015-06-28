class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        vector<int> cur(3,0);
        vector<int> end(3,0);
        for (int i = 0; i < prices.size()-1; ++i){
            int diff = prices[i+1] - prices[i];
            for (int i = 2; i >=1; i--){
                cur[i] = max(end[i-1]+max(0,diff), cur[i]+diff);
                end[i] = max(end[i], cur[i]);
            }
        }
        return end[2];
    }
};