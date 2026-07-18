class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int n=nums.size();
        int m=numsDivide.size();
        int gcd=numsDivide[0];
        for(int i=1; i<m; i++){
            cout<<gcd<<endl;
            gcd = __gcd(gcd, numsDivide[i]);
        }

        sort(nums.begin(), nums.end());

        int count=0;
        for(int i=0; i<n; i++){
            cout<<gcd<<" "<<nums[i]<<endl;
            if(gcd%nums[i] == 0){
                return count;   
            }
            count++;
        }

        return -1;
    }
};