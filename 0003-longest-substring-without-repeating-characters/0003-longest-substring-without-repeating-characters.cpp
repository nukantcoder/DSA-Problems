class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0 || n == 1)
        {
            return n;
        }
        unordered_map<char,int>freq;
        int i = 0;
        int j = 0;
        int maxlength = 0;

        while(j < n)
        {
            freq[s[j]]++;
            while(freq[s[j]] > 1)
            {
                freq[s[i]]--;
                i = i + 1;
            }
            maxlength = max(maxlength,j - i + 1);
            j = j + 1;
        }

        return maxlength;
    }
};