class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int n1 = m + n;
        int mid1 = (n1/2) - 1;
        int mid2 = mid1 + 1;
        int element1;
        int element2;
        int i = 0;
        int j = 0;
        int count = -1;
        while(i < m && j < n)
            {
                if(nums1[i] <= nums2[j])
                {
                    count++;
                    if(count == mid1)
                    {
                        element1 = nums1[i];
                    }
                    if(count == mid2)
                    {
                        element2 = nums1[i];
                    }
                    i++;
                }
                else
                {
                                        count++;
                    if(count == mid1)
                    {
                        element1 = nums2[j];
                    }
                    if(count == mid2)
                    {
                        element2 = nums2[j];
                    }
                    j++;
                }
            }
        while( i < m)
            {
                    count++;
                    if(count == mid1)
                    {
                        element1 = nums1[i];
                    }
                    if(count == mid2)
                    {
                        element2 = nums1[i];
                    }
                    i++;
            }
        while(j < n)
            {
                                    count++;
                    if(count == mid1)
                    {
                        element1 = nums2[j];
                    }
                    if(count == mid2)
                    {
                        element2 = nums2[j];
                    }
                    j++;
            }
        if(n1 % 2 == 0)
        {
            return double((double(element1) + double(element2))/2.0);
        }
        else
        {
            return double(element2);
        }
        
        
    }
};