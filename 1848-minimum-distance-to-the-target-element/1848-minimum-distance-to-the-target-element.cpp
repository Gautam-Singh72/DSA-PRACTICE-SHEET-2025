class Solution {
public:
    const int INF=1e9;
    //  T.C->O(N) AND S.C->O(1)
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans=INF;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==target){
                ans=min(ans, abs(start-i));
            }
        }
        return ans;
    }
};