class Solution {
public:
string shiftbyone(string s)
{
    int n = s.size();
    char last = s[0];
    for(int i = 0;i < n - 1;i++)
    {
        s[i] = s[i + 1];
    }
    s[n - 1] = last;
    return s;
}
    bool rotateString(string s, string goal) {
        
        int n = s.size();
        int m = goal.size();

        if(n != m) return false;

        for(int i = 1;i <= n;i++)
        {
            s = shiftbyone(s);
            if(s == goal)
            {
                return true;
            }
        }
        return false;
    }
};