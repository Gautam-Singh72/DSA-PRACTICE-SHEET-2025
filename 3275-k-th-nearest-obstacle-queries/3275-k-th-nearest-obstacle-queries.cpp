class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> pq;
        vector<int> res;

        for(vector<int> query: queries){
            int x=query[0];
            int y=query[1];
            int d=abs(x)+abs(y);
            pq.push(d);
            if(pq.size()>k){
                pq.pop();
            }
            if(pq.size()==k){
                res.push_back(pq.top());
                continue;
            }
            res.push_back(-1);
        }

        return res;
    }
};