class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minP = prices[0];
        int maxProfit = 0;
        for(int i = 1 ; i < prices.size() ; i++){
            minP = min(minP , prices[i]);
            int profit = prices[i]-minP;
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};
