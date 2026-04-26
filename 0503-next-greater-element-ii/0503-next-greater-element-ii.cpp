class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        vector<int>ans;
        int n = nums.size();

        int i;
        for(i = 2 * n - 1;i >= n;i--)
        {
            int ind = i % n;
            while(st.size() != 0)
            {
                if(nums[ind] < st.top())
                {
                    st.push(nums[ind]);
                    break;
                }
                else
                {
                    st.pop();
                }
            }
            if(st.size() == 0)
            {
                st.push(nums[ind]);
            }
        }

        for(i = n - 1;i >= 0;i--)
        {
             while(st.size() != 0)
            {
                if(nums[i] < st.top())
                {
                    ans.push_back(st.top());
                    st.push(nums[i]);
                    break;
                }
                else
                {
                    st.pop();
                }
            }
            if(st.size() == 0)
            {
                ans.push_back(-1);
                st.push(nums[i]);
            }
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};