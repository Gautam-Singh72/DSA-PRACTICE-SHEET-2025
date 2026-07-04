class Solution {
public:
    vector<bool> visited;
    void dfs(int u, int &res, unordered_map<int, vector<pair<int, int>>>& adj){

        visited[u]=true;
        for(pair<int, int> p: adj[u]){
            int v=p.first;
            int wt=p.second;
            res=min(res, wt);
            if(!visited[v]){
                dfs(v, res, adj);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        visited.resize(n, false);
        unordered_map<int, vector<pair<int, int>>> adj;
        for(vector<int>& edge: roads){
            int u=edge[0]-1;
            int v=edge[1]-1;
            int wt=edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        int res=INT_MAX;
        dfs(0, res, adj);

        return res;
    }
};