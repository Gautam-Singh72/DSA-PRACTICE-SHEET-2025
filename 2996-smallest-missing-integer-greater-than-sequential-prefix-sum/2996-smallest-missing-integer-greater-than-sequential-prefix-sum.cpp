class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        if(n==1)    return nums[0]+1;
        int sum=nums[0];
        unordered_set<int> s(nums.begin(), nums.end());
       
        for(int j=1; j<n; j++){
            if(nums[j] != nums[j-1]+1){
                break;
            }
            sum+=nums[j];
        }
        while(s.contains(sum)){
            sum++;
        }

        return sum;
    }
};