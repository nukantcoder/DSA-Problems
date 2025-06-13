class Solution {
public:
     long long hrs(vector<int>& piles,int mid)
     {
        long long total = 0;
        for(int i = 0; i < piles.size();i++)
        {
            total = ceil((double)piles[i]/mid) + total;
        }
        return total;
     }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int high = piles[0];
        for(int i = 1;i < n;i++)
        {
          high = max(piles[i],high);
        }

        int low = 1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            long long totalhrs = hrs(piles,mid);
            if(totalhrs <= h)
            {
                high = mid - 1;
            }
            else
            {
               low = mid + 1;
            }
        }
        return low;
    }
};