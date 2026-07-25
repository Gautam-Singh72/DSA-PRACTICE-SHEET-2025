class Solution {
public:
    int maxProduct(int n) {
        vector<int> freq(10, 0);

        while(n>0){
            freq[n%10]++;
            n/=10;
        }
        int res=1;
        int count=2;
        for(int i=9; i>=0; i--){
            if(count==0)    return res;
            while(freq[i] && count){
                res*=i;
                count--;
                freq[i]--;
            }
        }

        return res;
    }
};