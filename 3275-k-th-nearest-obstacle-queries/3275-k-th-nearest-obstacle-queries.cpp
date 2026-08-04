class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        int n=queries.size();
        priority_queue<int> pq;
        vector<int> res(n, -1);
        int count=1;
        for(vector<int>& query: queries){
            int x=query[0];
            int y=query[1];
            int d=abs(x)+abs(y);
            pq.push(d);
            if(pq.size()>k){
                pq.pop();
            }
            if(count<k){ count++; continue; }

            
            res[count-1]=pq.top();
            count++;
        }

        return res;
    }
};