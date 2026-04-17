class Solution {
public:
    void threeSum(int i, int j, int first, long long target, vector<int>& nums, vector<vector<int>>& ans){

        for(int k=i; k<=j; k++){
            if(k>i && nums[k]==nums[k-1])   continue;
            long long newTarget=target-nums[k];
            int s=k+1, e=j;
            while(s<e){
                if(nums[s]+nums[e]>newTarget){
                    e--;
                }else if(nums[s]+nums[e]<newTarget){
                    s++;
                }else{
                    while(s<e && nums[s]==nums[s+1])   s++;
                    while(s<e && nums[e]==nums[e-1])    e--;
                    ans.push_back({first, nums[k], nums[s], nums[e]});
                    s++; e--;
                }
            }
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n=nums.size();
        for(int i=0; i<n-3; i++){
            if(i>0 && nums[i]==nums[i-1])   continue;
            long long newTarget=target-nums[i];
            threeSum(i+1, n-1, nums[i], newTarget, nums, ans);
        }

        return ans;
    }
};