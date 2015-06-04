class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i){
            int dis = prices[i] - prices[i-1];
            if (dis > 0){
                profit += dis;
            }
        }
        return profit;
    }
};