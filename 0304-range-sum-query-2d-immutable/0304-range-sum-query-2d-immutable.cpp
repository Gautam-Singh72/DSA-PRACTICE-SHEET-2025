class NumMatrix {
public:
    //T.C->O(m) and S.C->O(m*n)
    vector<vector<int>> prefixSum;
    NumMatrix(vector<vector<int>>& matrix) { //O(m*n)
        int m=matrix.size();
        int n=matrix[0].size();
        prefixSum.resize(m, vector<int>(n));
        for(int i=0; i<m; i++){
            prefixSum[i][0]=matrix[i][0];
            for(int j=1; j<n; j++){
                prefixSum[i][j]=prefixSum[i][j-1]+matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) { //O(m)
        int sum=0;
        while(row1 <= row2){
            sum+=(col1==0) ? prefixSum[row1][col2] : prefixSum[row1][col2]-prefixSum[row1][col1-1];
            row1++;
        }

        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */