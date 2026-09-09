class Solution {
public:
    long long countCommas(long long n) {
        if(n<=999)  return 0;

        long long lower=1000;
        int comma=1;
        long long res=0;
        while(lower <= n){
            long long upper=lower*1000-1;
            if(upper>n){
                upper=n;
            }

            long long count=upper-lower+1;
            res+=count*comma;
            comma+=1;
            lower*=1000;
        }

        return res;
    }
};