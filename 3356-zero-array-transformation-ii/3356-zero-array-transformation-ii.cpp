class Solution {
public:
    //O(n+k)
    bool possible(vector<int>& nums, vector<vector<int>>& queries, int k){
        int n=nums.size();
        vector<int> diff_arr(n, 0);
        for(int i=0; i<k; i++){
            int st=queries[i][0];
            int end=queries[i][1]+1;
            int delta=queries[i][2];

            diff_arr[st]-=delta;
            if(end<n)   diff_arr[end]+=delta;
        }
        int cum_sum=diff_arr[0];
        for(int i=1; i<n; i++){
            cum_sum+=diff_arr[i];
            diff_arr[i]=cum_sum;
        }
        for(int i=0; i<n; i++){
            if(nums[i]+diff_arr[i]>0)   return false;
        }

        return true;
    }
    //O(n*log(k))
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=queries.size();
        int start=0;
        int end=n;
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;

            if(possible(nums, queries, mid)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }

        return ans;
    }
};