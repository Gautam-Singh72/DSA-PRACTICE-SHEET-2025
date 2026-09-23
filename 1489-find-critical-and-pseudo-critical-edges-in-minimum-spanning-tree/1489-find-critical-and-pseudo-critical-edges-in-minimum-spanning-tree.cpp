class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
        return a[2] < b[2];
    }
    class DSU{
        public:
        vector<int> parent;
        vector<int> rank;
        DSU(int n){
            parent.resize(n);
            rank.resize(n);
            for(int i=0; i<n; i++){
                parent[i]=i;
                rank[i]=1;
            }
        }

        int find(int i){
            if(i==parent[i])    return i;

            return parent[i]=find(parent[i]);
        }
        void Union(int x, int y){
            int parent_x=find(x);
            int parent_y=find(y);

            if(parent_x != parent_y){
                if(rank[parent_x] > rank[parent_y]){
                    parent[parent_y]=parent_x;
                }else if(rank[parent_x] < rank[parent_y]){
                    parent[parent_x]=parent_y;
                }else{
                    parent[parent_y]=parent_x;
                    rank[parent_x]++;
                }
            }
        }
    };
    int kruskal(int n, vector<vector<int>>& edges, int skip_edge, int forced_edge){
        int m=edges.size();
        DSU uf(n);

        int sum=0;
        if(forced_edge != -1){
            int u=edges[forced_edge][0];
            int v=edges[forced_edge][1];
            int wt=edges[forced_edge][2];
            uf.Union(u, v);
            sum+=wt;
        }

        for(int i=0; i<m; i++){
            if(i==skip_edge)    continue;

            int parent_u=uf.find(edges[i][0]);
            int parent_v=uf.find(edges[i][1]);
            if(parent_u != parent_v){
                uf.Union(edges[i][0], edges[i][1]);
                sum+=edges[i][2];
            }
        }
        for(int i=0; i<n; i++){
            if(uf.find(i) != uf.find(0)){
                return INT_MAX;
            }
        }
        return sum;
    }
    vector<vector<int>> solve(int n, vector<vector<int>>& edges){
        int m=edges.size();
        for(int i=0; i<m; i++){
            edges[i].push_back(i);
        }

        //sort the edges by weight
        sort(edges.begin(), edges.end(), compare);

        int weight_MST=kruskal(n, edges, -1, -1);
        vector<int> critical;
        vector<int> pseudo;

        for(int i=0; i<m; i++){
            if(kruskal(n, edges, i, -1) > weight_MST){
                critical.push_back(edges[i][3]);
            }else if(kruskal(n, edges, -1, i) == weight_MST){
                pseudo.push_back(edges[i][3]);
            }
        }
        
        return {critical, pseudo};
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        
        return solve(n, edges);
    }
};