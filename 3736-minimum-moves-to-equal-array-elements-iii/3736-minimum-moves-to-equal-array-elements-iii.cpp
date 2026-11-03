class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int count=0;

        int maxi_element=*max_element(nums.begin(), nums.end());

        for(int &num: nums){
            count+=maxi_element-num;
        }

        return count;
    }
};