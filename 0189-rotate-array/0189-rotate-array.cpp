class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        
        int n = arr.size();
        int d = k % n;
        // Brute Force would to rotate one by one k times
        //Better Approach i saw the solution so first we will shift the elements from i = n - d to i < n and then another i = 0 to i < n - d  into another array or vector
        //Optimal approach i could clearly see some swapping and reversing taking place using that logic

        reverse(arr.begin(),arr.end());
        reverse(arr.begin(),arr.begin() + d);
        reverse(arr.begin() + d,arr.end());
    }
};