class Solution {
public:
    //one pass solution T.C->O(N)
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int maxi=INT_MIN;
        for(int i=0; i<n; i++){
            if(colors[i]!=colors[0]){
                maxi=max(maxi, i);
            }
            if(colors[i] != colors[n-1]){
                maxi=max(maxi, abs(i-(n-1)));
            }
        }

        return maxi;
    }
};