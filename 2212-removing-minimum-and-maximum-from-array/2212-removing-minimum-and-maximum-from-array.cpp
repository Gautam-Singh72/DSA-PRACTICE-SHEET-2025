class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int mini=0;
        int maxi=0;
        for(int i=1; i<n; i++){
            if(nums[mini]<nums[i]){
                mini=i;
            }
            if(nums[maxi]>nums[i]){
                maxi=i;
            }
        }
        int ans=0;
        ans=min(max(mini+1, maxi+1), max(n-maxi, n-mini));
        int f_b = (mini+1)+(n-maxi);
        int b_f = (n-mini)+(maxi+1);
        ans=min({ans, f_b, b_f});

        return ans;
    }
};