class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        int current = 0;
        int nse = 0;
        int pse = 0;
        int area = 0;
        st.push(0);
        for(int i = 1;i < n;i++)
        {
            while(!st.empty() && heights[st.top()] > heights[i])
            {
                current = st.top();
                st.pop();
                nse = i;
                if(!st.empty())
                {
                    pse = st.top();
                }
                else
                {
                    pse = -1;
                }
                area = max(area,heights[current]*(nse - pse - 1));
            }
            st.push(i);
        }

        while(st.size() != 0)
        {
                current = st.top();
                st.pop();
                nse = n; //here since no elements are left but elemets still remain in stack so for them no next smaller element exisits so we will take as n
                if(!st.empty())
                {
                    pse = st.top();
                }
                else
                {
                    pse = -1;
                }
                area = max(area,heights[current]*(nse - pse - 1));
        }

        return area;
    }
};