class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());



        return min({abs(nums[n-2]-nums[1]), abs(nums[n-1]-nums[2]), abs(nums[n-3]-nums[0])});
    }
};