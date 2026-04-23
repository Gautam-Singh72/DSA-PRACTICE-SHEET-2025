class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1])   continue;
            int target=-nums[i];
            int l=i+1; int r=n-1;
            while(l<r){
                if(nums[l]+nums[r]==target){
                    while(l<r && nums[r]==nums[r-1]) r--;
                    while(l<r && nums[l]==nums[l+1]) l++;   
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++; r--;
                }else if(nums[l]+nums[r]>target){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return res;
    }
};