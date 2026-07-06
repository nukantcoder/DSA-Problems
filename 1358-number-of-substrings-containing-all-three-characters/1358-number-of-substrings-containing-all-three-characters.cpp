class Solution {
public:
    int numberOfSubstrings(string s) {
        //The main idea behind the optimal approach is instaed of finding all the subarrays expand to find the minimum valid window from index i and then count the valid subarrays using n - right then shrink the window because we have counted the number of subarrays from current i and so on 
        //Baisc idea is expand right to find minimal valid substring 

        int n = s.size();
        int ans = 0;
        unordered_map<char,int>mp;

        int i = 0;
        int j = 0;
        while(j < n)
        {
            mp[s[j]]++;
            while(mp.size() == 3)
            {
                ans = ans + (n - j);
                mp[s[i]]--;
                if(mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};