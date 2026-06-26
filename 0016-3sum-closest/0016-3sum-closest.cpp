class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int ans=INT_MAX;
        int minDiff=INT_MAX;
        for(int i=0; i<n-2; i++){
            int start=i+1;
            int end=n-1;
            int x=target-nums[i];
            while(start<end){
                if(nums[start]+nums[end]==x){
                    return target;
                }
                else if(nums[start]+nums[end]<x){
                    int diff=abs(x-nums[start]-nums[end]);
                    if(diff<minDiff){
                        ans=nums[i]+nums[start]+nums[end];
                        minDiff=diff;
                    }
                    start++;
                }else{
                    int diff=abs(x-nums[start]-nums[end]);
                    if(diff<minDiff){
                        ans=nums[i]+nums[start]+nums[end];
                        minDiff=diff;
                    }
                    end--;
                }
            }
        }
        return ans;
    }
};