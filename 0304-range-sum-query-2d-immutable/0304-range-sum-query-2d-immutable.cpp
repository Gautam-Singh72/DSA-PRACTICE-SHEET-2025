class NumMatrix {
public:
    //T.C->O(m) and S.C->O(m*n)
    vector<vector<int>> pref;
    NumMatrix(vector<vector<int>>& matrix) { //O(m*n) precomputation
        int m=matrix.size();
        int n=matrix[0].size();
        pref.resize(m+1, vector<int>(n+1));
        for(int i=1; i<=m; i++){
            // prefixSum[i][0]=matrix[i][0];
            for(int j=1; j<=n; j++){
                pref[i][j]=matrix[i-1][j-1] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) { //O(1)
        //converting query in 1 base indexing
        int x1=row1+1, y1=col1+1;
        int x2=row2+1, y2=col2+1;

        int incl1=pref[x2][y2];
        int excl1=pref[x1-1][y2];
        int excl2=pref[x2][y1-1];
        int incl2=pref[x1-1][y1-1];

        return incl1 - excl1 - excl2 + incl2;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */