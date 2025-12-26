class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        int currentsum = 0;
        for(int i = 0;i < n;i++)
        {
            currentsum = currentsum + nums[i];
        }

        int totalsum = 0;
        for(int i = 0;i <= n;i++)
        {
            totalsum = totalsum + i; 
        }

        return totalsum - currentsum;
    }
};