class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int>ans;
        int n = nums.size();
        int count1 = 0;
        int count2 = 0;
        int element1,element2;
        for(int i = 0;i < n;i++)
        {
            if(count1 == 0 && nums[i] != element2)
            {
                count1 = 1;
                element1 = nums[i];
            }
            else if(count2 == 0 && nums[i] != element1)
            {
                count2 = 1;
                element2 = nums[i];
            }
            else if(element1 == nums[i])
            {
                count1++;
            }
            else if(element2 == nums[i])
            {
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        int count3 = 0;
        int count4 = 0;
        for(int i = 0;i < n;i++)
        {
            if(nums[i] == element1)
            {
                count3++;
            }
            if(nums[i] == element2)
            {
                count4++;
            }
        }

        if(count3 > (n/3))
        {
            ans.push_back(element1);
        }
        if(count4 > (n/3) && element1 != element2)
        {
            ans.push_back(element2);
        }
        return ans;
    }
};