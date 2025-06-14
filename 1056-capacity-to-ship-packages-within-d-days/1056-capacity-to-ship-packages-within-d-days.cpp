class Solution {
public:
    int result(vector<int>& weights,int mid)
    {
        int day = 1;
        int wt = 0;
        for(int i = 0;i < weights.size();i++)
        {
            if(wt + weights[i] > mid)
            {
                day = day + 1;
                wt = weights[i];
            }
            else
            {
                wt = wt + weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0;
        int high = 0;
        int n = weights.size();
        for(int i = 0;i < n;i++)
        {
            low = max(low,weights[i]);
            high = high + weights[i];
        }
        int ans;
        while(low <= high)
        {
            int mid = (low + high)/2;
            int daysreq = result(weights,mid);
            if(daysreq <= days)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};