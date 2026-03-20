class Solution {
public:

bool isvalid(vector<string>& board,int row,int col,int n)
{
     //upward direction check
     for(int i = row;i >= 0;i--)
     {
        if(board[i][col] != '.')
        {
            return false;
        }
     }

     //upright diagnol check

     int i = row;
     int j = col;
     while(i >= 0 && j < n)
     {
           if(board[i][j] != '.')
        {
            return false;
        }
        i--;
        j++;
     }

     //upleft diagnol check

     i = row;
     j = col;

     while(i >= 0 && j>= 0)
     {
            if(board[i][j] != '.')
        {
            return false;
        }
        i--;
        j--;
     }
     return true;
}
void solve(vector<vector<string>>& ans,vector<string>& board,int row,int n)
{
    if(row == n)
    {
        ans.push_back(board);
        return;
    }


    for(int col = 0;col < n;col++)
    {
        if(isvalid(board,row,col,n) == true)
        {
            board[row][col] = 'Q';
            solve(ans,board,row + 1,n);
            board[row][col] = '.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        solve(ans,board,0,n);
        return ans;
    }
};