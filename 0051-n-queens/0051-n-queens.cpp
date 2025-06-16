class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
         vector<vector<string>>result;
          vector<string>board(n,string(n,'.'));
           vector<int>leftrow(n,0);
           vector<int>diag1(2*n-1,0);
           vector<int>diag2(2*n-1,0);
           solve(0,result,board,leftrow,diag1,diag2,n);
           return result;
    }
    void solve(int col, vector<vector<string>>& result, vector<string>& board, 
               vector<int>& leftrow, vector<int>& diag1, vector<int>& diag2, int n) {


    if(col==n){
        result.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(leftrow[row]==0 && diag1[row+col]==0 && diag2[n-1+col-row] ==0){
            board[row][col]='Q';
            leftrow[row]=1;
            diag1[row+col]=1;
            diag2[n-1+col-row]=1;
            solve(col+1,result,board,leftrow,diag1,diag2,n);
            board[row][col]='.';
            leftrow[row]=0;
            diag1[row+col]=0;
            diag2[n-1+col-row]=0;
        }
    }
    }
};