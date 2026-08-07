class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n, 1);
        
        int pref = nums[0];
        for(int i=1; i<n; i++){
            res[i]=pref;
            pref=pref*nums[i];
            
        }
        int suff=nums[n-1];
        for(int i=n-2; i>=0; i--){
            res[i]*=suff;
            suff*=nums[i];
        }

        return res;
    }
};