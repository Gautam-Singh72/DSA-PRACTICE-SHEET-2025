class Solution {
public:
    void sieve(vector<bool>& isPrime){
        int n=isPrime.size();   //find all prime number less than N for example N=36 it find all prime number less than 36
        isPrime[0]=isPrime[1]=false;
        for(int i=2; i*i<n; i++){ 
            if(isPrime[i]){
                for(int j=i*i; j<n; j+=i){
                    isPrime[j]=false;
                }
            }
        }
    }
    int minOperations(vector<int>& nums) {
        int maxValue=*max_element(nums.begin(), nums.end());
        vector<bool> isPrime(maxValue+100, true);
        sieve(isPrime);
        int count=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            int j=nums[i];
            if(i%2){
                while(isPrime[j]){
                    j++;
                    count++;
                }
            }else{
                while(!isPrime[j]){
                    j++;
                    count++;
                }
            }
        }
        return count;
    }
};