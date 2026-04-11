class Solution {
public:
    void findPrimeInRange(vector<bool>& prime){
        prime[0]=prime[1]=false;
        int n=prime.size();
        for(int i=2; i*i<n; i++){
            if(prime[i]){
                for(int k=i*i; k<n; k+=i){
                    prime[k]=false;
                }
            }
        }
    }
    int minOperations(vector<int>& nums) {
        vector<bool> prime(1e5+100, true);
        findPrimeInRange(prime);
        int n=nums.size();
        int m=prime.size();
        int count=0;
        for(int i=0; i<n; i++){
            if(i%2==0){
                if(prime[nums[i]]==false){
                    int j=nums[i];
                    while(j<m && prime[j]==false){
                        count++;
                        j++;
                    }
                }
            }else{
                if(prime[nums[i]]==true){
                    int j=nums[i];
                    while(j<m && prime[j]==true){
                        count++;
                        j++;
                    }
                }
            }
        }
        return count;
    }
};