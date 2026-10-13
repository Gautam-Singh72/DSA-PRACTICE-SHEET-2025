class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        long long res=0;

        for(int i=0; i<n; i++){
            if(nums[i]<0)   nums[i]*=-1;
        }

        sort(nums.begin(), nums.end(), greater<int>());

        

        int len=(n-1)/2+1;
        for(int i=0; i<len; i++){
            res+=(1ll*nums[i]*nums[i]);
        }

        for(int i=len; i<n; i++){
            res-=(1ll*nums[i]*nums[i]);
        }

        return res;
    }
};