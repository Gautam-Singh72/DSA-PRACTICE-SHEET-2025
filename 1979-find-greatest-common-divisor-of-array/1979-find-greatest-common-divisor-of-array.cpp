class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi=-1;
        int mini=1001;

        for(int &num: nums){
            maxi=max(maxi, num);
            mini=min(mini, num);
        }

        return __gcd(maxi, mini);
    }
};