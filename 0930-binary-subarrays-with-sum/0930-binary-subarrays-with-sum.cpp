class Solution {
public:
//The main approach is since we were computing sums again and again in brute force we can use a prefixsum and map because now instead of recomputing we have a running sum and use map to store frequencies just check prefix = currentsum - goal if my prefix is present in map or not if it is present then add its occurences.
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int,int>mp;
        mp[0] = 1;
        int prefixsum = 0;
        int ans = 0;
        for(int i = 0;i < n;i++)
        {
            prefixsum += nums[i];
            int rem = prefixsum - goal;
            if(mp.find(rem) != mp.end())
            {
                ans = ans + mp[rem];
            }
            mp[prefixsum]++;
        }
        return ans;
    }
};