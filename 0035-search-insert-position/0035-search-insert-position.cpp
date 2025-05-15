class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n = nums.size();
        if(nums[0] > target)
        {
            return 0;
        }
        if(nums[n - 1] < target)
        {
            return n;
        }
          int index;
        for(int i = 0;i < n;i++)
        {
            if(nums[i] >= target)
            {
                index = i;
                break;
            }
        }
        return index;
    }
};