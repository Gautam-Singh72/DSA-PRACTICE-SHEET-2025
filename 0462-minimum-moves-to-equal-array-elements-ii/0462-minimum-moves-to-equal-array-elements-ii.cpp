class Solution {
public:
    int n;
    int findMoves(vector<int>& nums, int mid){
        int target=nums[mid];
        int count=0;
        for(int i=0; i<mid; i++){
            count+=abs(target-nums[i]);
        }

        for(int i=mid+1; i<n; i++){
            count+=abs(target-nums[i]);
        }

        return count;
    }
    int minMoves2(vector<int>& nums) {
        n=nums.size();

        sort(nums.begin(), nums.end());
        int mid=n/2;

        int res=0;
        if(n%2 != 0){
            res=findMoves(nums, mid);
            return res;
        }

        res=min(findMoves(nums, mid-1), findMoves(nums, mid));

        return res;
    }
};