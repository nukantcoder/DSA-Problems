class Solution {
public:
    int minAddToMakeValid(string s) {
        int close = 0;
        int open = 0;

        for(int i = 0;i < s.size();i++)
        {
            if(s[i] == '(')
            {
                close++;
            }
            else if(s[i] == ')' && close > 0)
            {
                close--;
            }
          else
          {
            open++;
          }
        }
        return open + close;
    }
};