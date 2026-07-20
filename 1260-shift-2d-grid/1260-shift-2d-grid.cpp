class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int sz=m*n;
        vector<int> arr(sz, 0);

        int idx=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                arr[idx]=grid[i][j];
                idx++;
            }
        }
        
        k=k%(sz);
        reverse(arr.begin(), arr.begin()+(sz-k));
        reverse(arr.begin()+(sz-k), arr.end());
        reverse(arr.begin(), arr.end());

        for(int i=0; i<sz; i++){
            cout<<arr[i]<<endl;
            int row=i/n;
            int col=i%n;

            grid[row][col]=arr[i];
        }

        return grid;
    }
};