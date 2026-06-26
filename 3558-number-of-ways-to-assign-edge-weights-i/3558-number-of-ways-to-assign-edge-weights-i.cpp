class Solution {
public:
    int M=1e9+7;
    void createGraph(vector<vector<int>>& edges, unordered_map<int, vector<int>>& adj){
        for(vector<int>& edge: edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    int bfs(int u, vector<bool>& visited, unordered_map<int, vector<int>>& adj){
        queue<int> q;
        q.push(u);
        visited[u]=true;
        int level=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz>0){
                int src=q.front();
                q.pop();
                for(int v: adj[src]){
                    if(!visited[v]){
                        q.push(v);
                        visited[v]=true;
                    }
                }
                sz--;
            }
            level++;
        }
        return level-1;
    }
    // int fact(int n){
    //     int fact=1;
    //     for(int i=2; i<=n; i++){
    //         fact=fact*i;
    //     }
    //     return fact;
    // }
    // int ncr(int n, int r){
    //     int a=fact(n);
    //     int b=fact(n-r)*fact(r)%M;

    //     return (a*(pow(b, M-2)%M))%M;
    // }
    long long pow(long long a, long long b){
        if(b==0)    return 1;

        int res=pow(a, b/2);
        if(b%2==1){
            return (1ll*res*res*a)%M;
        }
        return (1ll*res*res)%M;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size();
        int V=n+2;
        unordered_map<int, vector<int>> adj;
        createGraph(edges, adj);
        vector<bool> visited(V, false);
        int depth=0;
        for(int i=1; i<V; i++){
            if(!visited[i]){
                depth=max(depth, bfs(i, visited, adj));
            }
        }
        cout<<depth<<endl;
        

        return (int)pow(2, depth-1);  
    }
};