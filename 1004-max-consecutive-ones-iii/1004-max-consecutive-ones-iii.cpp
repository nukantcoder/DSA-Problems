class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //the optimized approach works on the sliding window approach in that as our window was getting invalid we were shrinking it to make it valid again but here as the window gets invalid we will move i also such that the window only grows when the condition is satisfied as it becomes invalid the maxlength still gets maintained while increasing i and j both by one place

        int n = nums.size();
        int maxlength = 0;
        int count = 0;

        int i = 0;
        int j = 0;

        while(j < n)
        {
            if(nums[j] == 0)
            {
                count++;
            }
            if(count > k)
            {
                if(nums[i] == 0)
                {
                    count--;
                }
                i++;
            }
            if(count <= k)
            {
 maxlength = max(maxlength,j - i + 1);
            }
            j = j + 1;
        }
        return maxlength;
    }
};