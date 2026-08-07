class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        int startTime=intervals[0][0];
        int endTime=intervals[0][1];
        for(int i=1; i<n; i++){
            int s=intervals[i][0];
            int e=intervals[i][1];
            if(s<=endTime){
                endTime=max(endTime, e);
            }else{
                res.push_back({startTime, endTime});
                startTime=s;
                endTime=e;
            }
        }
        res.push_back({startTime, endTime});

        return res;
    }
};