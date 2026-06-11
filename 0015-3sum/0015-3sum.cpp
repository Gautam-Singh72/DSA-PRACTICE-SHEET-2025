class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int i=0;
        while(i<n-2){
            while(i>0 && i<n-2 && nums[i]==nums[i-1])  i++;
            int target=-nums[i];

            int start=i+1; int end=n-1;
            while(start<end){
                if(nums[start]+nums[end]<target){
                    start++;
                }else if(nums[start]+nums[end]>target){
                    end--;
                }else{
                    while(start<end && nums[start]==nums[start+1]){
                        start++;
                    }
                    while(start<end && nums[end]==nums[end-1]){
                        end--;
                    }
                    res.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                }
            }
            i++;
        }
        return res;
    }
};