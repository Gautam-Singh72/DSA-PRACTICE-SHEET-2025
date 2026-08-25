class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, bool> mp;
        for(int &num: nums){
            mp[num]=1;
        }
        int multiple=k;
        while(mp.count(multiple)){
            multiple+=k;
        }

        return multiple;
    }
};