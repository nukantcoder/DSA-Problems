class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        
        int n = nums.size();

        if(n == 1)
        {
            return;
        }
        int i;
        for(i = 0;i < n;i++)
        {
            if(nums[i] == 0)
            {
                break;
            }
        }
        int j = i + 1;
        while(j < n)
        {
            if(nums[j] != 0)
            {
                swap(nums[i],nums[j]);
                i++;
            }
            j++;
        }

        //Two pointer clicked in my mind as if there is any rearrangement without any extra space or movement
    }
};