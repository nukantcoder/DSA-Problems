class Solution {
public:
    int number_of_parts(vector<int>& nums,int mid)
    {
        int parts = 1;
        int current = 0;
        for(int i = 0;i < nums.size();i++)
            {
                if(current + nums[i] <= mid)
                {
                    current = current + nums[i];
                }
                else
                {
                    parts++;
                    current = nums[i];
                }
            }
        return parts;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        int high = 0;
        for(int i = 0;i < n;i++)
            {
                low = max(low,nums[i]);
                high = high + nums[i];
            }

        while(low <= high)
            {
                int mid = (low + high)/2;
                int parts = number_of_parts(nums,mid);
                if(parts <= k)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
        return low;
    }
};