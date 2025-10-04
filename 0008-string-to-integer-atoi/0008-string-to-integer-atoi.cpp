class Solution {
public:
    int myAtoi(string s) {
        
        int n = s.size();
        int sign = 1;
        long  ans = 0;

        int i = 0;
        while(i < n && s[i] == ' ')
        {
            i++;
        }


        if(i < n && (s[i] == '+' || s[i] == '-'))
        {
            if(s[i] == '-')
            {sign = -1;
            i++;
            } 
            else
            {
                sign = 1;
                i++;
            }
        }
      
      while(i < n)
      {
        if(isdigit(s[i]))
        {
            ans = ans * 10 + (s[i] - '0');

            if((ans * sign) < INT_MIN) return INT_MIN;
            if((ans * sign) > INT_MAX) return INT_MAX;
        }
        else
        {
            break;
        }
        i++;
      }

      return (int)(ans*sign);

    }
};