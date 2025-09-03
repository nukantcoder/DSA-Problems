class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 0) return 0;

        unordered_set<int> s;
        for(int i = 0;i < n;i++)
        {
            s.insert(nums[i]);
        }
         int longest = 1;
         int count = 1;
        for(auto i : s)
        {
            if(s.find(i - 1) == s.end())
            {
                int x = i + 1;
                count = 1;
                while(s.find(x) != s.end())
                {
                    x++;
                    count++;
                }
                longest = max(longest,count);
            }
        }
        return longest;
    }
};