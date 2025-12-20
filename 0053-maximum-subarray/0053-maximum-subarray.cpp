class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int maxsum = INT_MIN;
        int currentsum = 0;

        for(int i = 0;i < n;i++)
        {
            currentsum += nums[i];
            if(currentsum > 0)
            {
                maxsum = max(maxsum,currentsum);
            }
            else
            {
                maxsum = max(maxsum,currentsum);
                currentsum = 0;
            }
        }
        return maxsum;
    }
};