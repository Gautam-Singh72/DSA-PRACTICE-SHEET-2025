class Solution {
public:
    int solve(int N, int M, vector<int>& nums){
        int n=nums.size();
        int maxLeftSubSum=0;

        for(int i=0; i<N; i++){
            maxLeftSubSum+=nums[i];
        }
        int rightSubSum=0;
        for(int i=N; i<N+M; i++){
            rightSubSum+=nums[i];
        }
        
        int res=maxLeftSubSum+rightSubSum;
        int leftSubSum=maxLeftSubSum;
        int start=N; int end=N+M;
        int i=0; int j=N;
        while(end<n){
            rightSubSum+=nums[end];
            rightSubSum-=nums[start];
            start++; end++;
            leftSubSum+=nums[j];
            leftSubSum-=nums[i];
            i++; j++;

            maxLeftSubSum=max(maxLeftSubSum, leftSubSum);

            res=max(res, maxLeftSubSum+rightSubSum);
        }
        return res;
    }   
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        
        int res=solve(firstLen, secondLen, nums);
        res=max(res, solve(secondLen, firstLen, nums));

        return res;
    }
};