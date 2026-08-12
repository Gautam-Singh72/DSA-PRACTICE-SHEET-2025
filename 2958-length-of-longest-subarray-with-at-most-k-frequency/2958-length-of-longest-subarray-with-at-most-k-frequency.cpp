class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int start=0, end=0;
        int n=nums.size();
        int maxLen=-1;
        unordered_map<int, int> mp;
        while(end<n){
            mp[nums[end]]++;
            while(mp[nums[end]]>k){
                mp[nums[start]]--;
                start++;
            }
            maxLen=max(maxLen, end-start+1);
            end++;
        }
        return maxLen;
    }
};