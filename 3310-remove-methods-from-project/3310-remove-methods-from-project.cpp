class Solution {
public:

    void findSuspicious(int u, vector<int>& visited, unordered_map<int, vector<int>>& adj){
        visited[u]=-1;

        for(int &v: adj[u]){
            if(!visited[v]){
                findSuspicious(v, visited, adj);
            }
        }
    }
    bool canRemoveGroup(int u, vector<int>& visited, unordered_map<int, vector<int>>& adj){
        visited[u]=1;

        for(int &v: adj[u]){
            if(visited[v]==-1)  return false;
            if(!visited[v]){
                if(!canRemoveGroup(v, visited, adj)){
                    return false;
                }
            }
        }

        return true;
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int, vector<int>> adj;
        vector<int> visited(n, 0);

        for(vector<int>& edge: invocations){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
        }
        findSuspicious(k, visited, adj);
        vector<int> res;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                if(!canRemoveGroup(i, visited, adj)){
                    for(int i=0; i<n; i++){
                        res.push_back(i);
                    }
                    return res;
                }
            }
        }

        for(int i=0; i<n; i++){
            if(visited[i] == -1)    continue;
            res.push_back(i);
        }

        return res;
    }
};