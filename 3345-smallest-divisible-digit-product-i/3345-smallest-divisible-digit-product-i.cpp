class Solution {
public:
    int calculateProd(int n){
        int prod=1;
        while(n){
            int rem=n%10;
            prod*=rem;
            n/=10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        int rem=n%10;
        if(rem == 0)    return n;

        int iteration=10-rem;
        int res=iteration + n; //the maximum number is the nearest number which have a zero
        while(iteration--){
            int prod=calculateProd(n);
            
            if(prod % t == 0)   return n;
            n++;
        }

        return res;
    }
};