class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = colSum.size();
        int m = rowSum.size();
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                int val = min(rowSum[i],colSum[j]);
                matrix[i][j]=val;
                rowSum[i]-=val;
                colSum[j]-=val;
            }
        }
        return matrix;
    }
};