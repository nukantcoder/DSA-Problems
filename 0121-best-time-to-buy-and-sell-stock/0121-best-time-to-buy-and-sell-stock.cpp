class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        //Brute Force Approach is find all the profit possible using nested loops
        //Optimal Approach i thought was we can track the minimum alongwith maxprofit and updating both while traversing the array

        int maxprofit = 0;
        int currentmin = prices[0];
        for(int i = 1;i < n;i++)
        {
            maxprofit = max(maxprofit,prices[i] - currentmin);

           currentmin = min(currentmin,prices[i]);
        }
        return maxprofit;

        //atlast if it works i am surprised because the logic clicked very quickly because i had done it earlier 
    }
};