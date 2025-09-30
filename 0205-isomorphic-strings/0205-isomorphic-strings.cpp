class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        unordered_map<char,char> freqs;
        unordered_map<char,char> freqt;

       for(int i = 0;i < n;i++)
       {
        char c1 = s[i];
        char c2 = t[i];
        if(freqs.find(c1) != freqs.end() && freqs[c1] != c2 || 
        freqt.find(c2) != freqt.end() && freqt[c2] != c1)
        {
            return false;
        }
        freqs[c1] = c2;
        freqt[c2] = c1;
       }
       return true;
    }
};