class Solution {
public:
int result(vector<int>& nums,int mid)
{
    int value = 0;
    for(int i = 0;i < nums.size();i++)
    {
        value = value + ceil((double)nums[i]/(double)mid);
    }
    return value;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int n = nums.size();
        int ans;
        int high = nums[0];
        for(int i = 1;i < n;i++)
        {
            high = max(nums[i],high);
        }

        int low = 1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            int sum = result(nums,mid);
            if(sum <= threshold)
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