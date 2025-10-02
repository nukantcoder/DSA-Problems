class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int n = s.size();
        int m = t.size();

        if(n != m) return false;

        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;

        for(int i = 0;i < n;i++)
        {
            mp1[s[i]]++;
        }
        for(int i = 0;i < m;i++)
        {
            mp2[t[i]]++;
        }

        set<char> st;
        for(int i = 0;i < n;i++)
        {
            st.insert(s[i]);
        }

for(auto i : st)
{
    if(mp1[i] != mp2[i])
    return false;
}
return true;

    }
};