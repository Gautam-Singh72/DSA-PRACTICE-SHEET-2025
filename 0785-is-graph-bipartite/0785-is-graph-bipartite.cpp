class Solution {
public:
    bool solve(int u, int c, vector<int>& color, vector<vector<int>>& graph){
        color[u]=c;

        for(int &v: graph[u]){
            if(color[v] != -1 && color[v]==color[u])    return false;

            if(color[v] == -1){
                if(solve(v, c^1, color, graph) == false){
                    return false;
                }
            }
                
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();

        vector<int> color(V, -1);

        for(int i=0; i<V; i++){
            if(color[i] == -1){
                if(solve(i, 0, color, graph) == false){
                    return false;
                }
            }
        }
        
        return true;
    }
};