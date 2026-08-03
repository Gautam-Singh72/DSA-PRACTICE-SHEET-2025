class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, bool> mp;
        for(int num: nums){
            mp[num]=true;
        }

        int res=n+1;
        for(int i=0; i<n; i++){
            if(!mp.count(i+1)){
                return i+1;
            }
        }

        return res;
    }
};