class Solution {
public:
int ans(int a,int b)
{
    if(b % a == 0)
    {
        return a;
    }
    return ans(b % a,a);
}
    int gcdOfOddEvenSums(int n) {
        int sumodd  = 0;
        int sumeven = 0;

        for(int i = 1;i <= n * 2;i++)
        {
            if(i % 2 == 0)
            {
                sumeven = sumeven + i;
            }
            else
            {
              sumodd = sumodd + i;
            }
                 
        }
       return ans(sumodd,sumeven);
    
    }
};