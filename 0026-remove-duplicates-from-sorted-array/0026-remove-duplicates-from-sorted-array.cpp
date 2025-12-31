class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        //Brute Force Approach using extra space we can make an vector or an array consisting of all unique elements by traversing array one time and then overwrite the original array with this new array so that all the unique elements comes in front
        //Optimal Approach is using a two pointer approach since there is some rearrangement and array is sorted

        int n = nums.size();
        int i;
        for(i = 1;i < n;i++)
        {
            if(nums[i] == nums[i - 1])
            {
                break;
            }
        }
        int s = i - 1;
        int e = s + 1;
        while(e < n)
        {
            if(nums[s] != nums[e])
            {
               s++;
               swap(nums[s],nums[e]);
            }
            e++;
        }
        return s+1;
    }
};