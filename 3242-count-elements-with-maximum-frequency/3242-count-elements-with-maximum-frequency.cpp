class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(100,0);
        int maxi=-1;
        for(int i=0; i<nums.size(); i++){
            freq[nums[i]-1]++;
            maxi=max(maxi, freq[nums[i]-1]);
        }
        int count=0;
        for(int i=0; i<100; i++){
            if(freq[i]==maxi){
                count+=freq[i];
            }
        }
        return count;
    }
};