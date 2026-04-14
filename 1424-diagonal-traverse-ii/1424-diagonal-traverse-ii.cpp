class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m=nums.size();
        vector<int> ans;
        map<int, vector<int>> mp;
        for(int i=0; i<m; i++){
            for(int j=0; j<nums[i].size(); j++){
                mp[i+j].push_back(nums[i][j]);
            }
        }
        for(auto it: mp){
            for(int i=it.second.size()-1; i>=0; i--){
                ans.push_back(it.second[i]);
            }
        }
        return ans;
    }
};