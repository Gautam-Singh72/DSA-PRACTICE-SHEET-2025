class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        vector<pair<int, int>> events;
        for(vector<int>& interval: intervals){
            int start=interval[0];
            int end=interval[1]+1;
            
            events.push_back({start, 1});
            events.push_back({end, -1});
        }
        sort(events.begin(), events.end());
        int m=events.size();
        long long count=0; long long res=0;
        for(int i=0; i<m; i++){
            count+=events[i].second;
            if(events[i].second==1){
                res+=(count-1);
            }
        }
        return res;
    }
};