class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int current_sum = 0;
        for(int i = 0;i < n;i++)
            {
                current_sum += nums[i];
                if(current_sum >= 0)
                {
                    ans = max(ans,current_sum);
                }
                else
                {
                    ans = max(ans,current_sum);
                    current_sum = 0;
                }
            }
        return ans;
    }
};