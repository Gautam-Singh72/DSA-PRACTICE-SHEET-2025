class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<p> pq;

        for(vector<int>& point: points){
            int x=point[0];
            int y=point[1];
            int d=(x*x + y*y);
            pq.push({d, {x, y}});
            if(pq.size()>k){
                pq.pop();
            }
        }

        vector<vector<int>> res;
        while(!pq.empty()){
            pair<int, int> point=pq.top().second;
            int x=point.first;
            int y=point.second;
            pq.pop();
            res.push_back({x, y});
        }

        return res;
    }
};