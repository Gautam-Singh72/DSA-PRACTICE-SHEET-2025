class Solution {
public:
    int dfs(int u, int par, unordered_map<int, vector<int>>& adj, vector<bool>& hasApple){


        int time=0;
        for(int &child: adj[u]){
            if(child==par)    continue;

            int t=dfs(child, u, adj, hasApple);
            if(t>0 || hasApple[child]){
                time+=2+t;
            }
        }

        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int E=edges.size();
        unordered_map<int, vector<int>> adj;
        for(int i=0; i<E; i++){
            int u=edges[i][0];
            int v=edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return dfs(0, -1, adj, hasApple);
    }
};