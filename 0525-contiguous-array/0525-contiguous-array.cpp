class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                nums[i]=-1;
            }
        }
        mp[0]=-1;
        int maxLen=0;
        int prefSum=0;
        for(int i=0; i<n; i++){
            prefSum+=nums[i];
            if(mp.count(prefSum)){
                maxLen=max(maxLen, i-mp[prefSum]);
            }else{
                mp[prefSum]=i;
            }
        }
        return maxLen;
    }
};