class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();

        stack<int>st;//stack is used since we want to compare elements with last processed element so only option is stack
        st.push(arr[0]);

        for(int i = 1;i < n;i++)
        {
            bool alive = true;
            while(alive == true && !st.empty() && st.top() > 0 && arr[i] < 0)
            {
                if(abs(st.top()) > abs(arr[i]))
                {
                    alive = false;
                    break;
                }
                else if(abs(arr[i]) > abs(st.top()))
                {
                    st.pop();
                }
                else
                {
                    st.pop();
                    alive = false;
                    break;
                }
            }
            if(alive == true)
            st.push(arr[i]);
        }

        vector<int>ans;
        while(st.size() != 0)
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};