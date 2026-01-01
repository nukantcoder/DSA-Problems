class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        //Brute Force could be done using Sorting
        //Better Approach could be using extra space
        //Optimal Approach using Moores Voting algorithm

        int count = 1;
        int element = nums[0];
        int n = nums.size();

        for(int i = 1;i < n;i++)
        {
            if(nums[i] == element)
            {
                count++;
            }
            else
            {
                count--;
            }

            if(count == 0)
            {
                element = nums[i];
                count = 1;
            }
        } 
        return element;
    }
};