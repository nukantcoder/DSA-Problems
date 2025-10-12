class Solution {
public:
vector<int> lpsfind(string pattern)
{
    int n = pattern.size();
    vector<int>lps(n,0);

    int prefix = 0;
    int suffix = 1;
    lps[0] = 0;

    while(suffix < n)
    {
        if(pattern[prefix] == pattern[suffix])
        {
            lps[suffix] = prefix + 1;
            prefix++;
            suffix++;
    }
    else
    {
        if(prefix == 0)
        {
            lps[suffix] = 0;
            suffix++;
        }
        else
        {
            prefix = lps[prefix - 1];
        }
    }
    }
    return lps;
}
    int strStr(string text, string pattern) {
        

        int n = text.size();
        int m = pattern.size();

        vector<int>lps = lpsfind(pattern);
        
        int f = 0;
        int s = 0;
        while(s < m && f < n)
        {
            if(text[f] == pattern[s])
            {
                f++;
                s++;
            }
            else
            {
                if(s == 0)
                {
                    f++;
                }
                else
                {
                    s = lps[s-1];
                }
            }
        }
        if(s == m)
        {
            return f - s;
        }
        else
        {
            return -1;
        }
    }
};