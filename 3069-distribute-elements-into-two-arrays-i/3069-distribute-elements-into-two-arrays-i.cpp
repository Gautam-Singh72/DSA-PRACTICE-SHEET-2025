class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        if(n==1)    return nums;
        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for(int i=2; i<n; i++){
            int lastElemArr1=arr1.back();
            int lastElemArr2=arr2.back();
            if(lastElemArr1 > lastElemArr2){
                arr1.push_back(nums[i]);
                continue;
            }
            arr2.push_back(nums[i]);
        }

        for(int &num: arr2) arr1.push_back(num);

        return arr1;
    }
};