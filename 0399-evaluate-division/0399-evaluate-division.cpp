class Solution {
public:
    unordered_map<string, bool> visited;
    double dfs(string &src, string &des, double prod, unordered_map<string, vector<pair<string, double>>>& adj){
        visited[src]=true;
        if(src==des)    return prod;

        for(pair<string, double> &p: adj[src]){
            string v=p.first;
            double w=p.second;
            if(visited.count(v))    continue;

            double ans=dfs(v, des, prod*w, adj);
            if(ans != -1.0) return ans;
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        int n=equations.size();
        vector<double> res;
        for(int i=0; i<n; i++){
            string src=equations[i][0];
            string des=equations[i][1];
            double weight=values[i];
            
            adj[src].push_back({des, weight});
            adj[des].push_back({src, 1/weight});
        }
        for(auto &query: queries){
            string src=query[0];
            string des=query[1];
            visited.clear();
            if(!adj.count(src)){
                res.push_back(-1.0);
                continue;
            }  
            res.push_back(dfs(src, des, 1.0, adj));
        }
        return res;
    }
};