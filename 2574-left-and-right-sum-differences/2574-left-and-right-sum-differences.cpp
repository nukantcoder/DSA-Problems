class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
        {
            return {0};
        }

        vector<int>left(n,0);
        vector<int>right(n,0);
        vector<int>ans;

        left[0] = nums[0];
        for(int i = 1;i < n;i++)
        {
            left[i] = left[i - 1] + nums[i];
        }

        right[n - 1] = nums[n - 1];
        for(int i = n - 2;i >= 0;i--)
        {
            right[i] = right[i + 1] + nums[i];
        }

        for(int i = 0;i < n;i++)
        {
            if(i == 0)
            {
                ans.push_back(abs(0 - right[i+1]));
            }
            else if(i == n - 1)
            {
                ans.push_back(abs(left[i - 1] - 0));
            }
            else
            {
                ans.push_back(abs(left[i - 1] - right[i + 1]));
            }

        }
        return ans;
    }
};