class Solution {
public:
    typedef long long ll;
    ll countSmallerLeft(ll mid, vector<int>& coins) { 
        ll correctedCount = 0;
        int n = coins.size();

        //2^n * n * log(maxCoin)
        for(int expressions = 1; expressions <= (1 << n)-1; expressions++) { //2^n-1 expressions
            ll lcm = 0;
            ll order = 0; //even or odd order of expressions

            for(int i = 0; i < n; i++) {
                if(expressions & (1 << i)) {
                    order++; //we have taken ith coin

                    if(lcm == 0) {
                        lcm = coins[i];
                    } else {
                        lcm = lcm * coins[i] / gcd(lcm, coins[i]);
                    }
                }
            }

            if(order % 2 == 0) { //even then subtract
                correctedCount -= mid/lcm;
            } else {
                correctedCount += mid/lcm;
            }
        }

        return correctedCount;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        ll start=*min_element(coins.begin(), coins.end());
        ll end=*max_element(coins.begin(), coins.end())*1ll*k;
        ll ans=-1;

        while(start<=end){

            ll mid=start+(end-start)/2;

            if(countSmallerLeft(mid, coins)>=k){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};