class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        int count = 0;
        int prefixsum = 0;
        freq[0] = 1;
        for(int i = 0;i < n;i++)
        {
            prefixsum += nums[i];
            int rem = prefixsum - k;
            if(freq.find(rem) != freq.end())
            {
                count = count + freq[rem];
            }
            freq[prefixsum]++;
        }
        return count;
    }
};