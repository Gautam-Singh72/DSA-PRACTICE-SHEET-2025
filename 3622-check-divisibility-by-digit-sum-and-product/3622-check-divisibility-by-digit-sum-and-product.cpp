class Solution {
public:
    bool checkDivisibility(int n) {
        int temp=n;
        int sum=0;
        int prod=1;
        while(n){
            int rem=n%10;
            sum+=rem;
            prod*=rem;

            n/=10;
        }

        return temp%(sum+prod)==0;
    }
};