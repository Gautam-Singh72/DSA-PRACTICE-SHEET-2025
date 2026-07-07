class Solution {
public:
    typedef long long ll;
    long long sumAndMultiply(int n) {
        ll sum=0;
        ll x=0;
        ll mul=1;
        while(n>0){
            ll rem=n%10;
            if(rem!=0){
                x += rem*mul;
                mul*=10;
                sum+=rem;
            }
            n/=10;
        }
        cout<<x<<" "<<sum;
        return sum*x;
    }
};