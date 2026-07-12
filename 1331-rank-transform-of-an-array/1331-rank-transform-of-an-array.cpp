class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        if(n==0)    return {};
        vector<vector<int>> v;
        for(int i=0; i<n; i++){
            v.push_back({arr[i], i});
        }
        sort(v.begin(), v.end());
        vector<int> res(n, 0);
        int rank=1;
        res[v[0][1]]=rank;
        for(int i=1; i<n; i++){
            if(v[i][0]==v[i-1][0]){
                res[v[i][1]]=rank;
                continue;
            }
            rank++;
            res[v[i][1]]=rank;
        }

        return res;
    }
};