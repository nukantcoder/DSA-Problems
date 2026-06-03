class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(n == k)
        {
            return "0";
 
        }
     
     stack<char>st;
     st.push(num[0]);

     for(int i = 1;i < n;i++)
     {
        while(st.size() != 0 && k > 0 && st.top() > num[i])// if we find that last processed number is greatr than than current number remove it as it will increase the string making it larger
        {
            st.pop();
            k = k - 1;
        }
        st.push(num[i]);
     }

     while(k != 0)// if there is a case when k remains unchanged so we will remove the k elements from the stack like in case when string is "12345" and k is 2 so result would be"123"
    {
        st.pop();
        k--;
    }

    string result = "";
    while(st.size() != 0)
    {
        result.push_back(st.top());//this part when i was using result = result + st.top() every time it was creating a new string string which gave me mle
        st.pop();
    }
    
    int j = result.size() - 1;
    while(result.size() != 1)// here in order to handele the edge cases where 1 or more zeroes remain i only remove till my result is not equal to one
    {
      char current = result[j];
      if(current == '0')
      {
        result.pop_back();
        j--;
      }
      else
      {
        break;
      }
    }

    reverse(result.begin(),result.end());
    return result;
   }
};