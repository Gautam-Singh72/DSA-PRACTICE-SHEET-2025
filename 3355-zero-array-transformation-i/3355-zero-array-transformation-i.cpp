class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> arr(n, 0);
        for(vector<int>& query: queries){
            int start=query[0];
            int end=query[1]+1;
            arr[start]-=1;
            if(end<n)   arr[end]+=1;
        }
        int cumm_sum=arr[0];
        for(int i=1; i<n; i++){
            cumm_sum+=arr[i];
            arr[i]=cumm_sum; 
        }
        for(int i=0; i<n; i++){
            if(nums[i]+arr[i]>0)    return false;
        }

        return true;
    }
};