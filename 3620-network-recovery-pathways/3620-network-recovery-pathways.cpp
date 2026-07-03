class Solution {
public:
    int n;
    long long ans=-1;
    vector<long long> dist;
    bool dij(int u, long long k, int req, vector<bool>& online, unordered_map<int, vector<pair<int, int>>>& adj){
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, u});
        dist[u]=0;

        while(!pq.empty()){
            auto par=pq.top();
            pq.pop();

            long long d=par.first;
            int node=par.second;
            if(dist[node]<d)    continue;
            for(pair<int, int> p:adj[node]){
                int v=p.first;
                long long wt=p.second;
                if(online[v] && wt>=req){
                    if(d+wt<dist[v]){
                        dist[v]=d+wt;
                        pq.push({dist[v], v});
                    }
                }
            }
        }
        return dist[n-1]<=k;
    }
    //creating adj list
    void createGraph(unordered_map<int, vector<pair<int, int>>>& adj, vector<vector<int>>& edges){
        for(vector<int>& edge: edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            adj[u].push_back({v, wt});
        }
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n=online.size();
        dist.resize(n, LLONG_MAX);

        unordered_map<int, vector<pair<int, int>>> adj;
        createGraph(adj, edges);

        int start=INT_MAX;
        int end=INT_MIN;
        for(vector<int>& edge: edges){
            start=min(start, edge[2]);
            end=max(end, edge[2]);
        }
        
        while(start<=end){
            int mid=start+(end-start)/2;
            dist.assign(n, LLONG_MAX);

            if(dij(0, k, mid, online, adj)){
                ans=mid;
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        
        return (int)ans;
    }
};