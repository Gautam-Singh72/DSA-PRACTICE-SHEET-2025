class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixGcd;
 
        int maxi=nums[0];
        prefixGcd.push_back(nums[0]);
        //n*log(max(nums[i]))
        for(int i=1; i<n; i++){
            maxi=max(maxi, nums[i]);
            int gcd=__gcd(maxi, nums[i]);
            prefixGcd.push_back(gcd);
        }

        //nlog(n)
        sort(prefixGcd.begin(), prefixGcd.end());

        int s=0; int e=n-1;
        long long sum=0;
        while(s<e){
            int temp=__gcd(prefixGcd[s], prefixGcd[e]);
            sum+=temp;
            s++;
            e--;
        }

        return sum;
    }
};