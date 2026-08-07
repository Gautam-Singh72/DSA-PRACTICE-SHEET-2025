class Solution {
public:
    vector<vector<int>> mergeInterval(vector<vector<int>>& intervals){
        int n=intervals.size();
        
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i=1; i<n; i++){

            if(intervals[i][0] <= res.back()[1]){
                res.back()[1]=max(res.back()[1], intervals[i][1]);
                continue;
            }
            res.push_back(intervals[i]);
        }

        return res;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        if(n==0)    return {newInterval};
        vector<vector<int>> temp;
        bool isInsert=false;
        for(int i=0; i<n; i++){
            if(newInterval[0] < intervals[i][0]){
                temp.push_back(newInterval);
                isInsert=true;
            }
            temp.push_back(intervals[i]);
        }
        if(!isInsert)   temp.push_back(newInterval);

        return mergeInterval(temp);     
    }
};