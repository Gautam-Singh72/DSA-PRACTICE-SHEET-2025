class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> ans;
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1>n2){
            return intersection(nums2, nums1);
        }
        for(int i=0; i<n1; i++){
            mp[nums1[i]]++;
        }
        for(int i=0; i<n2; i++){
            if(mp[nums2[i]]){
                ans.push_back(nums2[i]);
                mp.erase(nums2[i]);
            }
        }
        
        return ans;
    }
};