class Solution {
public:
    void update(int i, int l, int r, int idx, int val, vector<int>& st){
        if(l==r){
            st[i]+=val;
            return;
        }

        int mid=l+(r-l)/2;
        if(idx<=mid){
            update(2*i+1, l, mid, idx, val, st);
        }else{
            update(2*i+2, mid+1, r, idx, val, st);
        }
        st[i]=st[2*i+1]+st[2*i+2];
    }
    
    int sum(int i, int l, int r, int start, int end, vector<int>& st){
        if(r<start || l>end)    return 0;

        if(l>=start && r<=end)  return st[i];

        int mid=l+(r-l)/2;
        return sum(2*i+1, l, mid, start, end, st)+sum(2*i+2, mid+1, r, start, end, st);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> st(4*n, 0);

        vector<pair<int, int>> v;
        for(int i=0; i<n; i++){
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());

        vector<int> ans(n);
        for(auto& [elem, index]: v){
            update(0, 0, n-1, index, 1, st);
            ans[index]=sum(0, 0, n-1, index+1, n-1, st);
        }

        return ans;
    }
};