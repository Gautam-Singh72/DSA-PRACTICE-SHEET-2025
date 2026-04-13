class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int target=nums2[nums2.size()-1];
        int minDiff=INT_MAX;
        long long count=0;
        for(int i=0; i<nums1.size(); i++){
            int lower=min(nums1[i], nums2[i]);
            int upper=max(nums1[i], nums2[i]);
            if(target>=lower && target<=upper)  minDiff=0;
            minDiff=min({minDiff, abs(lower-target), abs(upper-target)});
            count+=abs(nums1[i]-nums2[i]);
        }

        return count+minDiff+1;
    }
};