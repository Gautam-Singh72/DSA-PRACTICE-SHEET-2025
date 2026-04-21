class Solution {
public:
    //two pass solution
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int maxi=INT_MIN;
        int i=0;
        while(colors[i] == colors[n-1]){
            i++;
        }
        maxi=max(maxi, abs(i-(n-1)));
        i=n-1;
        while(colors[i] == colors[0]){
            i--;
        }
        maxi=max(maxi, i); //max(maxi, abs(0-i));

        return maxi;
    }
};