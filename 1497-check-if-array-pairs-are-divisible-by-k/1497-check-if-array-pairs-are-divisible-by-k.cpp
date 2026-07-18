class Solution {
public:
    int countPairDivisibleByK(int k, vector<int>& arr){
        int n=arr.size();
        unordered_map<int, int> freq;

        int count=0;
        for(int i=0; i<n; i++){

            int rem=arr[i]%k;
            int compliment=k-rem;
            if(compliment==k){
                count+=freq[0];
                if(freq[0]>0){
                    freq[0]--;
                    continue;
                }
                
            }else{
                count+=freq[compliment];
                if(freq[compliment]>0){
                    freq[compliment]--;
                    continue;
                } 
            }
            freq[rem]++;
        }
        return count;
    }
    bool canArrange(vector<int>& arr, int k) {
        
        vector<int> freq(k, 0);
        for(int num: arr){
            int rem=((num % k) + k ) % k;
            freq[rem]++;
        }
        //if the pair whose rem is 0 are odd then can not possible to divide
        if(freq[0]%2 != 0){
            return false;
        }
        // 0 1 2 3  k=4
        for(int i=1; i<=(k-1)/2; i++){
            if(freq[i] != freq[k-i])    return false;
        }

        if(k%2==0 && freq[k/2]%2 != 0){
            return false;
        }

        return true;
    }
};