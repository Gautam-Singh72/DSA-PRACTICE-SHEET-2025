class Solution {
public:
    static bool compare(vector<int> &a, vector<int>& b){
        if(a[0]<b[0])   return true;
        if(a[0]==b[0] && a[1]>b[1])   return true;

        return false;
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end(), compare);

        int i=0; int overlap=0;
        for(int j=i+1; j<n; j++){
            int start=intervals[j][0];
            int end=intervals[j][1];
            if(start>=intervals[i][0] && end<=intervals[i][1]){
                overlap++;
            }else{
                i=j;
            }
        }
        return n-overlap;
    }
};