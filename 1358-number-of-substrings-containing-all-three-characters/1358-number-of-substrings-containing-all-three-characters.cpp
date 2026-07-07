class Solution {
public:
int minval(int a,int b,int c)
{
    if(a <= b && a <= c) return a;
    else if(b <= a && b <= c) return b;
    else return c;
}
    int numberOfSubstrings(string s) {
        //The main idea behind this approach is to count how many substrings can end at this particular index in order to tell how many substrings are valid at this particular index just see the minimum vlaue between lasta lastb and last c since minimum value indicates this is valid substring and to left to it are all valid substrings

        int n = s.size();
        int lastA = -1;
        int lastB = -1;
        int lastC = -1;
        int ans = 0;

        for(int i = 0;i < n;i++)
        {
            if(s[i] == 'a') lastA = i;
            if(s[i] == 'b') lastB = i;
            if(s[i] == 'c') lastC = i;

            if(lastA >= 0 && lastB >= 0 && lastC >= 0)
            {
                int val = minval(lastA,lastB,lastC);
                ans = ans + val + 1;
            }
        }
        return ans;
    }
};