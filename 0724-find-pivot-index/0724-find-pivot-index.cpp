class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int req_sum=0;
        for(int i=0;i<nums.size();i++){
            req_sum+=nums[i];
            if(req_sum-nums[i]==sum-req_sum){
                return i;
            }
        }
        return -1;
    }
};