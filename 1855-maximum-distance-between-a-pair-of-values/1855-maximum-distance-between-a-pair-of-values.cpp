class Solution {
public:
    //T.C-O(N*log(M)) and S.C->O(1)
    int find_farthestPoint(int s, int e, int target, vector<int>& nums2){
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums2[mid]>=target){
                ans=mid;
                s=mid+1;
            }else{
                e=mid-1;
            }   
        }
        return ans;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int maxi=INT_MIN;
        for(int i=0; i<n; i++){
            int target=nums1[i];
            int j=find_farthestPoint(i, m-1, target, nums2);
            if(j!=-1){
                maxi=max(maxi, j-i);
            }
        }
        return maxi==INT_MIN ? 0 : maxi;
    }
};