class Solution {
public:
// The basic idea in this question is not only find the cards combination which will give maxscore but to see the that left behind always forms a continguous sequence totalsum = pickedsum + remainingsum if we could find the contingous set of elements with the minimum sum we could maximize the picked cards using the sliding window technique 
    int maxScore(vector<int>& arr, int k) {
        
        int n = arr.size();
        int totalsum = 0;
        for(int i = 0;i < n;i++)
        {
            totalsum += arr[i];
        }

        if(k == n)
        {
            return totalsum;
        }

        int maxscore = 0;
        int windowsum = 0;
        int i = 0;
        int j = n - k - 1;// because i have to find the remaining contingous window of sizze n - k 

        for(int ind = i;ind <= j;ind++)
        {
            windowsum = windowsum + arr[ind];
        }

        maxscore = max(maxscore,totalsum - windowsum);
        windowsum = windowsum - arr[i];
        i = i + 1;
        j = j + 1;

        while(j < n)
        {
            windowsum = windowsum + arr[j];
              maxscore = max(maxscore,totalsum - windowsum);
             windowsum = windowsum - arr[i];
             i = i + 1;
             j = j + 1;
        }

        return maxscore;
    }
};