class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string ans = "";
        int count = 0;
        int i = 0;
        while(i < n)
        {
            if(s[i] == '(')
            {
                if(count > 0)
                {
                    ans += s[i];
                }
                count++;
            }
            else
            {
                count--;
                if(count > 0)
                {
                   ans += s[i];
                }
            }
            i++;
        }
        return ans;
    }
};