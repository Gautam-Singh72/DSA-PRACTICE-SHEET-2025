class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;
        for(int i=0; i<nums2.size(); i++){
            while(!st.empty() && nums2[i]>nums2[st.top()]){
                mp[nums2[st.top()]]=nums2[i];
                st.pop();
            }
            st.push(i);
        }
        for(int i=0; i<nums1.size(); i++){
            if(mp.find(nums1[i]) != mp.end())
                nums1[i]=mp[nums1[i]];
            else
                nums1[i]=-1;
        }
        return nums1;
    }
};