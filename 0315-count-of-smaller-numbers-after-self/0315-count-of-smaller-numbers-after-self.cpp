class Solution {
public:
    void merge(int start, int mid, int end, vector<int>& ans, vector<pair<int, int>>& numsPair){
        vector<pair<int, int>> temp(end-start+1);
        int i=start, j=mid+1;
        int k=0;
        while(i<=mid && j<=end){
            if(numsPair[i].first > numsPair[j].first){
                ans[numsPair[i].second]+=(end-j+1);
                temp[k++]=numsPair[i++];
            }else{
                temp[k++]=numsPair[j++];
            }
        }

        while(i<=mid){
            temp[k++]=numsPair[i++];
        }
        while(j<=end){
            temp[k++]=numsPair[j++];
        }
        i=start; k=0;
        while(i<=end){
            numsPair[i++]=temp[k++];
        }
    }
    void mergeSort(int start, int end, vector<int>& ans, vector<pair<int, int>>& numsPair){
        if(start>=end)   return;

        int mid=start+(end-start)/2;
        mergeSort(start, mid, ans, numsPair);
        mergeSort(mid+1, end, ans, numsPair);
        merge(start, mid, end, ans, numsPair);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        vector<pair<int, int>> numsPair;
        for(int i=0; i<n; i++){
            numsPair.push_back({nums[i], i});
        }
        mergeSort(0, n-1, ans, numsPair);

        return ans;
    }
};