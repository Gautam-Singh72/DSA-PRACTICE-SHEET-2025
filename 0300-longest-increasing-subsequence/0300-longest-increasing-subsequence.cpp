class Solution {
public:
    //patence sorting n*(log n)
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> res;
        for(int num: nums){
            auto it=lower_bound(res.begin(), res.end(), num);
            if(it==res.end()){
                res.push_back(num);
            }else{
                res[it-res.begin()]=num;
            }
        }

        return res.size();
    }
};