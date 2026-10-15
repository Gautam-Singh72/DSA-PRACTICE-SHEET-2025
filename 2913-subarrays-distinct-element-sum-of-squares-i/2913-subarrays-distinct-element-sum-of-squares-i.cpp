class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int freq[101];

        int res=0;
        for(int i=0; i<n; i++){
            int count=0;
            fill(begin(freq), end(freq), 0);
            for(int j=i; j<n; j++){
                if(freq[nums[j]]==0){
                    count++;
                }
                freq[nums[j]]++;
                res+=(count*count);
            }
        }
        return res;
    }
};