class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int maxarea = 0;

        int n = heights.size();
        vector<int>NSE(n,0);
        vector<int>PSE(n,0);

        //Next Smaller element
        NSE[n - 1] = n;
        st.push(n - 1);
        for(int i = n - 2;i >= 0;i--)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if(!st.empty() && heights[st.top()] < heights[i])
            {
                NSE[i] = st.top();
            }
            if(st.empty())
            {
                NSE[i] = n;
            }
            st.push(i);
        }

        while(st.size() != 0)
        {
            st.pop();
        }

        //previous smaller element

        PSE[0] = -1;
        st.push(0);
        for(int i = 1;i < n;i++)
        {
             while(!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if(!st.empty() && heights[st.top()] < heights[i])
            {
                PSE[i] = st.top();
            }
            if(st.empty())
            {
                PSE[i] = -1;
            }
            st.push(i);
        }

        for(int i = 0;i < n;i++)
        {
            maxarea = max(maxarea,heights[i] *(NSE[i] - PSE[i] - 1));
        }
        return maxarea;
    }
};