class Solution {
public:
    double myPow(double x, int n) {
    
    if(x == 0) return 0.0;
    if(n == 0) return 1.0;

    long int new_n = n; 
     if(n < 0)
     {
        x = 1/x;
        new_n = -(new_n);
     }   

    
     double ans = 1;
     while(new_n > 0)
     {
        if(new_n % 2 == 1)
        {
            ans = ans * x;
        }
        x = x * x;
        new_n = new_n / 2;
     }
     return ans;
    }
};