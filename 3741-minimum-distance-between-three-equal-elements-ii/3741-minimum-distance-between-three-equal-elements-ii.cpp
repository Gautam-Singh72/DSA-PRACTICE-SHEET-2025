class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size(); int ans=INT_MAX;
        unordered_map<int, vector<int>>mp;
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        for(auto &it: mp){
            auto &v=it.second;
            if(v.size()<3)    continue;
            for(int i=0; i<v.size()-2; i++){
                int a=v[i];
                int c=v[i+2];
                int dist=2*(c-a);
                ans=min(ans, dist);
            }
        }
        return ans==INT_MAX? -1: ans;
    }
};