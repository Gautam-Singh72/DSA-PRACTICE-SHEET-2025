class NumArray {
public:

    vector<int> nums;
    vector<int> blockSum;
    int blockSize;
    NumArray(vector<int>& arr) {
        nums=arr;
        int n=nums.size();
        blockSize=ceil(sqrt(n));
        blockSum.resize(blockSize, 0);
        for(int i=0; i<n; i++){ //O(n)
            int b=i/blockSize;
            blockSum[b]+=nums[i];
        }
    }
    
    void update(int index, int val) { //O(1)
        int blockIndex=index/blockSize;
        int prevValue=nums[index];
        nums[index]=val;
        blockSum[blockIndex]-=prevValue;
        blockSum[blockIndex]+=val;
    }
    
    int sumRange(int left, int right) { //O(sqrt(n)) 
        int startBlock=left/blockSize;
        int endBlock=right/blockSize;
        int sum=0;
        if(startBlock == endBlock){
            for(int i=left; i<=right; i++){
                sum+=nums[i];
            }
            return sum;
        }else{
            //left block
            int startIndex=left;
            int endIndex=(startBlock+1)*blockSize-1;
            for(int i=startIndex; i<=endIndex; i++){
                sum+=nums[i];
            }
            //mid block
            int midBlockStart=startBlock+1;
            int midBlockEnd=endBlock-1;
            for(int i=midBlockStart; i<=midBlockEnd; i++){
                sum+=blockSum[i];
            }
            //end block
            int endBlockstartIndex=endBlock*blockSize;
            int endBlockendIndex=right;
            for(int i=endBlockstartIndex; i<=endBlockendIndex; i++){
                sum+=nums[i];
            }
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */