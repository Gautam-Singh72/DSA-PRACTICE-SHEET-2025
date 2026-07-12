class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        if(n==0)    return {};
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++){
            v.push_back({arr[i], i});
        }
        sort(v.begin(), v.end());
        vector<int> res(n, 0);
        int rank=1;
        res[v[0].second]=rank;
        for(int i=1; i<n; i++){
            if(v[i].first==v[i-1].first){
                res[v[i].second]=rank;
                continue;
            }
            rank++;
            res[v[i].second]=rank;
        }

        return res;
    }
};