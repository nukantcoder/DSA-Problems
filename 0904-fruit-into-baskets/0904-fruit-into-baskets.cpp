class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //First of all the question says that i have to pick the maximum fruits such that each basket can have only 1 type fruit so i can think of as the longest substring of atmost 2 unique fruits 
        // The brute force approach is to try to find each subarray using 2 loops and using a set in each case to store the elements and as soon as the elements . 2 that means it violates the condition so break and start another subarray

        // A better approach would be to use a two pointers + sliding window technique and a map to store the frequencies of fruits so expand the window till mp.size() <= 2 and as soon as mp.size() > 2 shrink the window untill it becomes a valid window

        int n = fruits.size();
        unordered_map<int,int>mp;
        int maxlength = 0;

        int i = 0;
        int j = 0;

        while(j < n)
        {
            mp[fruits[j]]++;
            while(mp.size() > 2)
            {
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0)
                {
                    mp.erase(fruits[i]);
                }
                i++;
            }
            maxlength = max(maxlength,j - i + 1);
            j++;
        }
        return maxlength;
    }
};