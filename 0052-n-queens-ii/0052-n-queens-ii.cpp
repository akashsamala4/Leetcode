class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<int>leftrow(n,0);
        vector<int>diag1(2*n-1,0);
        vector<int>diag2(2*n-1,0);
        solve(0,n,count,leftrow,diag1,diag2);
            return count;
        }
        void solve(int col, int n, int &count, vector<int>& leftrow, vector<int>& diag1, vector<int>& diag2) {
            if(col==n){
                count++;
                return;
            }for(int row = 0;row<n;row++){
                if(leftrow[row]==0 && diag1[row+col]==0 && diag2[n-1+row-col]==0){
                    leftrow[row]=1;
                    diag1[row+col]=1;
                    diag2[n-1+row-col]=1;
                    solve(col+1,n,count,leftrow,diag1,diag2);
                    leftrow[row]=0;
                    diag1[row+col]=0;
                    diag2[n-1+row-col]=0;
                }
            }
        
    }
};