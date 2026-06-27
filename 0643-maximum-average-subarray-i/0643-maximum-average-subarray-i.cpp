class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = k - 1;
        int sum = 0;
        double current;
        double maxaverage;

        for(int ind = i;ind <= j;ind++)
        {
            sum = sum + nums[ind];
        }
        current = double(sum) / k;
        maxaverage = current;
        sum = sum - nums[i];
        i = i + 1;
        j = j + 1;

        while(j < n)
        {
            sum = sum + nums[j];
            current = double(sum)  / k;
            maxaverage = max(current,maxaverage);
            sum = sum - nums[i];
             i = i + 1;
             j = j + 1;
        }
        return maxaverage;
    }
};