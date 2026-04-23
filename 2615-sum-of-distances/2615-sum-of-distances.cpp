class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<long long, long long> freq;
        unordered_map<long long, long long> prefsum;
        int n=nums.size();
        vector<long long> res(n, 0);
        for(int i=0; i<n; i++){
            if(freq.count(nums[i])){
                long long fq=freq[nums[i]];
                long long sum=prefsum[nums[i]];
                res[i]+=1ll*fq*i - sum;
            }
            freq[nums[i]]++;
            prefsum[nums[i]]=prefsum[nums[i]]+i;
        }
        freq.clear();
        prefsum.clear();
        for(int i=n-1; i>=0; i--){
            if(freq.count(nums[i])){
                long long fq=freq[nums[i]];
                long long sum=prefsum[nums[i]];
                res[i]+=sum - 1ll*fq*i;
            }
            freq[nums[i]]++;
            prefsum[nums[i]]=prefsum[nums[i]]+i;
        }
        return res;
    }
};