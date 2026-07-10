class Solution {
public:
//The main idea is instead of finding the subarrays with sum equal to goal find suarrays with sum <= goal and sum <= goal - 1 using sliding window exact subarrays = subarrays <= goal - subarrays <= goal - 1
int count(vector<int>& nums, int k)
{
    if(k < 0)
    {
        return 0;
    }
    int n = nums.size();
    int sum = 0;
    int count = 0;
    int i = 0;
    int j = 0;
    while(j < n)
    {
        sum = sum + nums[j];
        while(sum > k)
        {
            sum = sum - nums[i];
            i++;
        }
        count = count + (j - i + 1);
        j++;
    }
    return count;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return count(nums,goal) - count(nums,goal - 1);
    }
};