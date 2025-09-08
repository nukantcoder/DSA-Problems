class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstrow = false;
        bool firstcol = false;
        // First row mai koi zero check karne ke liye
        for(int col = 0;col < n;col++)
        {
            if(matrix[0][col] == 0)
            {
                firstrow = true;
                break;
            }
        }
       // First column mai koi zero check karne ke liye
        for(int row = 0;row < m;row++)
        {
            if(matrix[row][0] == 0)
            {
                firstcol = true;
                break;
            }
        }
       // Markers set karne ke liye 
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
    
        for(int i = 1;i < m;i++)
        {
           for(int j = 1;j < n;j++)
           {
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
           }
        }

        if(firstrow == true)
        {
        for(int col = 0;col < n;col++)
        {
              matrix[0][col] = 0;
        }
        }

        if(firstcol == true)
        {
            for(int row = 0;row < m;row++)
            {
                matrix[row][0] = 0;
            }
        }
    }
};