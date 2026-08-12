class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();

        priority_queue<int> pq;
        vector<pair<int, int>> arr;
        for(int i=0; i<n; i++){
            arr.push_back({capital[i], profits[i]});
        }
        sort(arr.begin(), arr.end());

        
        int idx=0;
        while(k--){
            int i=idx;
            while(i<n && arr[i].first<=w){
                pq.push(arr[i].second);
                i++; idx++;
            }
            if(!pq.empty()){
                int profit=pq.top();
                pq.pop();
                w+=profit;
                
            }
        }

        return w;
    }
};