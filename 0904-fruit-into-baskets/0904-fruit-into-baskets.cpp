class Solution {
public:
    int totalFruit(vector<int>& fruits) {
      // A small optimization over better approach my window was expanding untill my mp.size() <= 2 and as soon as window size > 2 my window was shrinking untill it became a valid window but instead of shrinking all the way i will shrink by one place
     // because in first iteratino untill j expands it will give me current maxlength but as soon as the window becomes invalid i will move i by 1 place and j by 1 place such that the maxlength does not exceed and as it is valid window j will keep expanding 

        int n = fruits.size();
        unordered_map<int,int>mp;
        int maxlength = 0;

        int i = 0;
        int j = 0;

        while(j < n)
        {
            mp[fruits[j]]++;
            if(mp.size() > 2)
            {
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0)
                {
                    mp.erase(fruits[i]);
                }
                i++;
            }
            if(mp.size() <= 2)
            {
maxlength = max(maxlength,j - i + 1);
            }
            j++;
        }
        return maxlength;
    }
};