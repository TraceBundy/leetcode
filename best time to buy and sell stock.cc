class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int max = 0;
        int end = 0;
        int i = 1;
        while (i < prices.size()){
            if (prices[i] - prices[i-1] + max > 0){
                max = prices[i] - prices[i-1] + max;
            } else {
                max = 0;
            }
            if (end < max) end = max;
            ++i;
        }
        return end;
    }
};