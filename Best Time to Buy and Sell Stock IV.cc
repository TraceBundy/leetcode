class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() < 2) return 0;
        if (prices.size() < 2*k) return slove(prices);
        vector<int> cur(k+1,0);
        vector<int> end(k+1,0);
        for (int i = 0; i < prices.size()-1; ++i){
            int diff = prices[i+1] - prices[i];
            for (int i = k; i >=1; i--){
                cur[i] = max(end[i-1]+max(0,diff), cur[i]+diff);
                end[i] = max(end[i], cur[i]);
            }
        }
        return end[k];
    }
    int slove(vector<int>& prices){
        int max = 0;
        for (int i = 0; i < prices.size()-1; ++i){
            int diff = prices[i+1] - prices[i];
            max += diff > 0 ? diff:0;
        }
        return max;
    }
};