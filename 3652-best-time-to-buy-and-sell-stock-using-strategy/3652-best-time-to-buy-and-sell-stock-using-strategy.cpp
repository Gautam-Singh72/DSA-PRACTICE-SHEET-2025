class Solution {
public:
    typedef long long ll;
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();

        vector<ll> v(n);
        for(int i=0; i<n; i++){
            v[i]=1ll*prices[i]*strategy[i];
        }

        vector<ll> v_pref(n);
        vector<ll> pref(n);
        v_pref[0]=v[0];
        pref[0]=prices[0];
        for (int i = 1; i < n; i++) {
            pref[i] = prices[i]+pref[i-1];
            v_pref[i]=v[i]+v_pref[i-1];
        }

        ll res=v_pref[n-1];
        for(int i=0; i<=n-k; i++){
            int c=k/2;
            int l=i+c;
            int r=i+k-1;

            ll profit=pref[r]-pref[l-1];

            int s=r+1;
            int e=n-1;
            if(s<=e)
                profit+=(s==0) ? v_pref[e] : v_pref[e]-v_pref[s-1];

            l=0;
            r=i-1;
            if(l<=r)
                profit+=(l==0) ? v_pref[r] : v_pref[r]-v_pref[l-1];

            res=max(res, profit);
        }

        return res;
    }
};