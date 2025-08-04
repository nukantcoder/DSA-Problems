class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i;
        for(i = 0;i < n;i++)
            {
                if(nums[i] == 1)
                    break;
            }
        int j = i + 1;
        while(j < n)
            {
                if(nums[j] != 1)
                {
                    swap(nums[i],nums[j]);
                    i++;
                }
                j++;
            }

        int k;
        for(k = 0;k < n;k++)
            {
                if(nums[k] == 2)
                    break;
            }

        int k2 = k + 1;
        while(k2 < n)
            {
                if(nums[k2] != 2)
                {
                    swap(nums[k],nums[k2]);
                    k++;
                }
                k2++;
            }
    }
};