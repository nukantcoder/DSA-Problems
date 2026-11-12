class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //The brute force approach is to simply sort the array and check for whether nums[i] == nums[i - 1] if true then it contains duplicate otherwise it does not 
        //TC: O(nlogn) AS:O(1)

        //The optimized approach is to use a map and keep track of frequencies of elements while checking their frequencies if the frequency of any element is >=2 then return true
        //TC:O(n) AS:O(n)

        int n = nums.size();

        if(n == 1)
        {
            return false;
        }
        unordered_map<int,int>freq;

        for(int i = 0;i < n;i++)
        {
            freq[nums[i]]++;

            if(freq[nums[i]] >= 2)
            {
                return true;
            }
        }
        return false;
    }
};