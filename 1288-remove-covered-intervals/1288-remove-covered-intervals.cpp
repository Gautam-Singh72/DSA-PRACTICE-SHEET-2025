class Solution {
public:
    static bool compare(vector<int> &a, vector<int>& b){
        if(a[0]<b[0])   return true;
        if(a[0]==b[0] && a[1]>b[1])   return true;

        return false;
    }
    //t.c-O(n*logn + n)=O(n*logn) and S.C-O(n) brute force
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end(), compare); //n*(logn)

        vector<vector<int>> result; //O(n) space 
        result.push_back(intervals[0]);
        for(int j=1; j<n; j++){ //O(n)
            int start=intervals[j][0];
            int end=intervals[j][1];
            if(start>=result.back()[0] && end<=result.back()[1]){
                continue;
            }
            result.push_back(intervals[j]);
        }
        return result.size();
    }
};