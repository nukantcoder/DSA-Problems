class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> psl(n, -1);
        vector<int> nsl(n, -1);
        stack<int> st;
        // psl(previous smaller element)
        for (int i = 0; i < n; i++) {
            while (st.size() != 0) {
                if (arr[i] > arr[st.top()]) {
                    psl[i] = st.top();
                    break;
                } else {
                    st.pop();
                }
            }

            if (st.size() == 0) {
                psl[i] = -1;
            }
            st.push(i);
        }

        while (st.size() != 0) {
            st.pop();
        }

        // next smaller element
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() != 0) {
                if (arr[i] >= arr[st.top()]) {
                    nsl[i] = st.top();
                    break;
                } else {
                    st.pop();
                }
            }

            if (st.size() == 0) {
                nsl[i] = n;
            }
            st.push(i);
        }

        int ans = 0;
        int mod = 1000000007;
        for(int i = 0;i < n;i++)
        {
            int left = i - psl[i];
            int right = nsl[i] - i;

            long long current = left * right;
            ans = (ans + (arr[i] * current) % mod) % mod; 
        }
        
        return ans;
    }
};