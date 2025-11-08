class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> v;
        for(int i=0; i<mat.size(); i++){
            int count=0;
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j]==1){
                    count++;
                }
            }
            v.push_back(count);
        }
        int maxi=v[0]; int idx=0;
        for(int i=1; i<v.size(); i++){
            if(maxi<v[i]){
                maxi=v[i];
                idx=i;
            }
        }
        vector<int>ans;
        ans.push_back(idx);
        ans.push_back(maxi);
        return ans;
    }
};