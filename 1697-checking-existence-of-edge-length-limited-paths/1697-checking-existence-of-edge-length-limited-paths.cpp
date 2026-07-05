class Solution {
public:
    int V;
    vector<int> parent;
    vector<int> rank;
    void createAdj(vector<vector<int>>& edgeList, unordered_map<int, vector<pair<int, int>>>& adj){
        for(vector<int>& edge: edgeList){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
    }
    bool dfs(int src, int dest, int &limit, vector<bool>& visited, unordered_map<int, vector<pair<int, int>>>& adj){
        if(src==dest)   return true;

        
        visited[src]=true;
        for(pair<int, int>& p: adj[src]){
            int v=p.first;
            int wt=p.second;
            if(!visited[v] && wt<limit){
                if(dfs(v, dest, limit, visited, adj)){
                    visited[src]=false;
                    return true;
                }   
            }
        }
        visited[src]=false;
        return false;
    }
    bool bfs(int src, int dest, int &limit, unordered_map<int, vector<pair<int, int>>>& adj){
        if(src == dest) return true;
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(src);
        visited[src]=true;

        while(!q.empty()){
            int u=q.front();
            if(u==dest) return true;
            q.pop();
            for(pair<int, int>& p: adj[u]){
                int v=p.first;
                int wt=p.second;
                if(!visited[v] && wt<limit){
                    Union(u, v);
                    q.push(v);
                    visited[v]=true;
                }
            }
        }
        return false;
    }
    int find(int i){
        if(parent[i]==i)    return i;

        return parent[i]=find(parent[i]);
    }
    void Union(int x, int y){
        int parent_x=find(x);
        int parent_y=find(y);

        if(parent_x != parent_y){
            if(rank[parent_x]>rank[parent_y]){
                parent[parent_y]=parent_x;
            }else if(rank[parent_x]<rank[parent_y]){
                parent[parent_x]=parent_y;
            }else{
                parent[parent_y]=parent_x;
                rank[parent_x]++;
            }
        }
    }
    static bool compare(vector<int>& a, vector<int>& b){
        if(a[2]<b[2])   return true;

        return false;
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        V=n;
        // unordered_map<int, vector<pair<int, int>>> adj;
        // createAdj(edgeList, adj);

        //assign parent and rank vector
        parent.resize(V);
        rank.resize(V);
        for(int i=0; i<V; i++){
            parent[i]=i;
            rank[i]=1;
        }
        //assign each query thier idx becoz sorting displace the query positions
        int m=queries.size();
        for(int i=0; i<m; i++){
            queries[i].push_back(i);
        }

        vector<bool> res(m, false);
        sort(edgeList.begin(), edgeList.end(), compare);
        sort(queries.begin(), queries.end(), compare);

        int j=0;
        //process each query one by one
        for(vector<int>& query: queries){
            int src=query[0];
            int dest=query[1];
            int limit=query[2];
            int idx=query[3];

            while(j<edgeList.size() && edgeList[j][2]<limit){
                int u=edgeList[j][0];
                int v=edgeList[j][1];
                Union(u, v);
                j++;
            }

            if(find(src)==find(dest)){
                res[idx]=true;
                continue;
            }
            res[idx]=false;
        }
        return res;

    }
};