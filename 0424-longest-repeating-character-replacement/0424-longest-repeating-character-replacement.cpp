class Solution {
public:
//The main logic behind this problem is to find out the minimum replacements which depened on current window size and max frequency character using a sliding window if my minimum replacements = window size - max character <= k expand the window and shring it becomes > k. Time Complexity:O(n) Auxilairy Space:O(26) for map
    int characterReplacement(string s, int k) {
        int n = s.size();
        if(n == 1 && k == 1)
        {
            return 1;
        }
        unordered_map<char,int> mp;
        int maxlength = 0;
        int maxfreq = 0;

        int left = 0;
        int right = 0;
        while(right < n)
        {
            mp[s[right]]++;
            maxfreq = max(maxfreq,mp[s[right]]);
            
            while((right - left + 1) - maxfreq > k)
            {
                mp[s[left]] = mp[s[left]] - 1;
                left++;
            }
            maxlength = max(maxlength,right - left + 1);
            right++;
        }
        return maxlength;
    }
};