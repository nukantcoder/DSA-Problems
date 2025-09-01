class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>ans;
        
        unordered_map<int,int> freq;
        int first = -1;
        int second = -1;
        for(int i = 0;i < n;i++)
        {
            int y = target - nums[i];
            if(freq.find(y) != freq.end())
            {
               first = i;
               second = freq[y];
            }
            if(first != -1)
            {
                break;
            }
            freq[nums[i]] = i;
        }
        ans.push_back(first);
        ans.push_back(second);
        return ans;

    }
};