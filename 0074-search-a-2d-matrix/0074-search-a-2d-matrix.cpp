class Solution {
public:
    bool find(vector<int>matrix,int target)
    {
        int n = matrix.size();
        int low = 0;
        int high = n - 1;
        while(low <= high)
            {
                int mid = (low + high)/2;
                if(matrix[mid] == target)
                {
                    return true;
                }
                else if(matrix[mid] < target)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0;i < m;i++)
            {
                if(target >= matrix[i][0]  && target <= matrix[i][n-1])
                {
                    if(find(matrix[i],target) == true)
                    {
                        return true;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        return false;
    }
};