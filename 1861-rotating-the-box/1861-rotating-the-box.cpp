class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n=boxGrid.size();
        int m=boxGrid[0].size();
        for(int i=0; i<n; i++){
            int empty_idx=-1;
            for(int j=m-1; j>=0; j--){
                if(boxGrid[i][j]=='.' && empty_idx==-1){
                    empty_idx=j;
                }
                if(boxGrid[i][j]=='*'){
                    empty_idx=-1;
                }
                if(boxGrid[i][j]=='#' && empty_idx!=-1 ){
                    swap(boxGrid[i][j], boxGrid[i][empty_idx]);
                    empty_idx--;
                }
            }
        }
        vector<vector<char>> res(m, vector<char>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                res[j][i]=boxGrid[i][j];
            }
        }
        for(int i=0; i<m; i++){
            vector<char>& v= res[i];
            reverse(v.begin(), v.end());
        }

        return res;
    }
};