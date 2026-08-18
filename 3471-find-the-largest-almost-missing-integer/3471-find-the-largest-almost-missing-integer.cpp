class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> freq(51, 0);
        for(int i=0; i<k; i++){
            freq[nums[i]]++;
        }
        for(int j=1; j<=n-k; j++){
            for(int i=j; (i-j)<k; i++){
                if(freq[nums[i]]>0){
                    freq[nums[i]]=-1;
                }else if(freq[nums[i]]==0){
                    freq[nums[i]]++;
                }
            }
        }
        int ans=-1;
        for(int i=0; i<51; i++){
            if(freq[i]>0){
                ans=max(ans, i);
            }
        }

        return ans;
    }
};