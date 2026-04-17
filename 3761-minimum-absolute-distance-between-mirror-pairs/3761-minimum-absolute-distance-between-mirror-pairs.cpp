class Solution {
public:
    int reverseNum(int num){
        string temp=to_string(num);
        reverse(temp.begin(), temp.end());

        return stoi(temp);
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=n-1; i>=0; i--){
            int rev=reverseNum(nums[i]);
            if(mp.count(rev)){
                ans=min(ans, abs(i-mp[rev]));
            }
            mp[nums[i]]=i;;
        }

        return ans==INT_MAX ? -1 : ans;
    }
};