class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //The basic approach behind this problem is instead of thinking to flip the zeroes and check for subarrays we can see each subarray could have maximum of k zeroes so we have to find longest subarray with maximum of k zeroes which could be easily done using sliding window + 2 pointers just expand the window till zeroes <= k as they exceed shrink the window till zeroes <= k

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
            while(count > k)
            {
                if(nums[i] == 0)
                {
                    count--;
                }
                i++;
            }
            maxlength = max(maxlength,j - i + 1);
            j = j + 1;
        }
        return maxlength;
    }
};