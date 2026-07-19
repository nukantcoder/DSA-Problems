class Solution {
public:
    string minWindow(string s, string t) {
        //The main approach approach is instead of trying to form a string which contains all characters of t start with end using a hashmap to store all the characters of t and count == t.size() that these many characters are reuired using sliding window / 2 pointer approach expand the window untill you find valid window as you find a valid window now shrink it untill its valid and find the minlength string

        int n = s.size();
        int minlength = max(s.size(),t.size());
        int start = -1;

        unordered_map<char,int> mp;
        for(int i = 0;i < t.size();i++)
        {
            mp[t[i]]++;
        }
        int i = 0;
        int j = 0;
        int count = t.size();

        while(j < n)
        {
            if(mp[s[j]] > 0)
            {
                count--;
            }
            while(count == 0)
            {
                if((j - i + 1) <= minlength)
                {
                    minlength = j - i + 1;
                    start = i;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0)
                {
                    count++;
                }
                i++;
            }
            mp[s[j]]--;
            j++;
        }
        if(start == -1)
        {
            return "";
        }
        else
        {
           return s.substr(start,minlength); 
        }
    }
};