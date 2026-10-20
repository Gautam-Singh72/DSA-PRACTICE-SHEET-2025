class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n=nums.size();

        int count=0;
        int numberOfTargetElement=0;
        for(int i=0; i<n; i++){
            if(target > nums[i]){
                count++;
            }

            if(nums[i]==target) numberOfTargetElement++;
        }

        vector<int> res;
        while(numberOfTargetElement--){
            res.push_back(count++);
        }

        return res;
    }
};