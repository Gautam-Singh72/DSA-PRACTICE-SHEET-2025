class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n=arr.size();
        cout<<n<<endl;
        cout<<arr[n-1]<<" ";
        if(arr[0]>1)    arr[0]=1;
        for(int i=0; i<n-1; i++){
            if(abs(arr[i]-arr[i+1])>1){
                arr[i+1]=arr[i]+1;
            }
        }

        return arr[n-1];
    }
};