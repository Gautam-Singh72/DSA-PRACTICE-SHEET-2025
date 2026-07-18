class Solution {
public:
    //T.C->O(m*(log(max(numsDivide[i]))) + n*log(n))
    //S.C->O(1)
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int n=nums.size();
        int m=numsDivide.size();
        int gcd=numsDivide[0];
        // m*(log(max(numsDivide[i])))
        for(int i=1; i<m; i++){
            gcd = __gcd(gcd, numsDivide[i]);
        }

        // n*log(n)
        sort(nums.begin(), nums.end());

        int count=0;
        for(int i=0; i<n; i++){ //O(n)
            if(gcd%nums[i] == 0){
                return count;   
            }
            count++;
        }

        return -1;
    }
};