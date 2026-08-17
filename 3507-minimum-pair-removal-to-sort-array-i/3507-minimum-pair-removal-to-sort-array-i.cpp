class Solution {
public:
    bool isIncrease(vector<int>& v){

        for(int i=1; i<v.size(); i++){
            if(v[i] < v[i-1]) return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        while(!isIncrease(nums) && nums.size()>1){
            count++;
            int minSum=INT_MAX;
            int idx1=-1, idx2=-1;
            for(int i=1; i<nums.size(); i++){
                int sum=nums[i]+nums[i-1];
                if(minSum > sum){
                    minSum=sum;
                    idx1=i-1;
                    idx2=i;
                }
            }
            vector<int> temp;
            int i=0;
            while(i<nums.size()){
                if(i==idx1){
                    temp.push_back(minSum);
                    i+=2;
                }else{
                    temp.push_back(nums[i]);
                    i++;
                }
            }
            nums.clear();
            nums=temp;
        }
        return count;
    }
};