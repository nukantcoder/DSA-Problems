class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0;
        int right = n - 1;
        while(top < m && right >= 0)
            {
                if(matrix[top][right] < target)
                {
                    top++;
                }
                else if(matrix[top][right] > target)
                {
                    right--;
                }
                else
                {
                    return true;
                }
            }
        return false;
    }
};