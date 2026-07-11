class Solution {
public:
    vector<bool> visited;
    void createGraph(unordered_map<int, vector<int>>& adj, vector<vector<int>>& edges){
        for(vector<int>& edge: edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    //dfs
    void dfs(int u, int &nodeCount, int &edgeCount, unordered_map<int, vector<int>>& adj){
        nodeCount++;
        visited[u]=true;

        for(int &v: adj[u]){
            edgeCount++;
            if(!visited[v]){
                dfs(v, nodeCount, edgeCount, adj);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        createGraph(adj, edges);
        visited.resize(n, false);

        int res=0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                int nodeCount=0; int edgeCount=0;
                dfs(i, nodeCount, edgeCount, adj);
                edgeCount/=2;
                int edgeReq=nodeCount*(nodeCount-1)/2;
                if(edgeCount == edgeReq)  res++;
            }
        }
        return res;
    }
};