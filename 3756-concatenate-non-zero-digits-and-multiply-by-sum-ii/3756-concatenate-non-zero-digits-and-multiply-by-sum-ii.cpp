class Solution {
public:
    const int M=1e9+7;
    typedef long long ll;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<ll>pow10(n+1, 0);
        pow10[0]=1;
        for(int i=1; i<=n; i++){
            pow10[i]=(pow10[i-1]*10) % M;
        }
        //precompute sum
        vector<ll> prefSum(n, 0);
        prefSum[0]=s[0]-'0';
        for(int i=1; i<n; i++){
            prefSum[i]=(prefSum[i-1]+(s[i]-'0'))%M;
        }
        //count digit
        vector<int> digitCount(n, 0);
        digitCount[0]=((s[0]-'0') != 0);
        for(int i=1; i<n; i++){
            if(s[i] != '0'){
                digitCount[i]=digitCount[i-1]+1;
            }else   
                digitCount[i]=digitCount[i-1];
        }
        //digit
        vector<ll> digit(n);
        digit[0]=(s[0] != '0') ? s[0]-'0' : 0;
        for(int i=1; i<n; i++){
            if(s[i] != '0'){
                digit[i]=(digit[i-1]*10 + (s[i]-'0')) % M;
                continue;
            }
            digit[i]=digit[i-1];
        }
        vector<int> res;
        for(vector<int>& query: queries){
            int start=query[0];
            int end=query[1];
            int sum=(start==0) ? prefSum[end] : prefSum[end]-prefSum[start-1];
            long long x=0;
            if(start==0){
                x=digit[end];
            }else{
                long long k=digitCount[end]-digitCount[start-1];
                x=(digit[end]-(digit[start-1]*pow10[k] % M) + M) % M;
            }
            
            int ans=(1LL*sum*x)%M;
            res.push_back( ans);
        }
        return res;
    }
};