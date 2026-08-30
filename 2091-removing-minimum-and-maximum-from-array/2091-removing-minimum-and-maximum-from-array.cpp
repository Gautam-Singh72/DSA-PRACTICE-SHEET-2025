class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int maxIdx=0;
        int minIdx=0;

        for(int i=1; i<n; i++){
            if(nums[i] > nums[maxIdx]){
                maxIdx=i;
            }
            if(nums[i] < nums[minIdx]){
                minIdx=i;
            }
        }

        int deleteFromFront=max(maxIdx, minIdx)+1;
        int deleteFromEnd=n-min(maxIdx, minIdx);

        int op3=min(maxIdx+1, n-maxIdx)+min(minIdx+1, n-minIdx);

        return min({deleteFromFront, deleteFromEnd, op3});

    }
};