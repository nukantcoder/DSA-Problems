class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minvalue = prices[0];
        int maxprofit = 0;
        for(int i = 0;i < n;i++)
            {
                minvalue = min(minvalue,prices[i]);

                maxprofit = max(maxprofit,prices[i] - minvalue);
            }
        return maxprofit;
    }
};