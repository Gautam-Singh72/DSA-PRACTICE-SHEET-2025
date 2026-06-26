class Solution {
public:
    //T.C-O(n*logn + q*log(n)) and S.C-O(n*log(n) + O(n) queue + O(max width of tree) stack space)
    const int M=1e9+7;
    vector<int> parent;

    //bfs --T.C-O(n)  and S.C-O(n) queue size in worst case
    void bfs(int u, vector<bool>& visited, vector<int>& levelOfEachNode, unordered_map<int, vector<int>>& adj){
        queue<int> q;
        q.push(u);
        parent[u]=-1;
        visited[u]=true;

        int level=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int src=q.front();
                q.pop();
                levelOfEachNode[src]=level;

                for(int v: adj[src]){
                    if(!visited[v]){
                        q.push(v);
                        parent[v]=src;
                        visited[v]=true;
                    }
                }
            }
            level++;
        }
    }
    //modular pow fun --log(max(width of tree))
    long long modPow(long long a, long long b){
        if(b==0)    return 1;
        long long res=modPow(a, b/2);
        if((b&1)!=0){
            return (1ll*res*res*a)%M;
        }

        return (1ll*res*res)%M;
    }

    //creating ancestorTable
    vector<vector<int>> ancestorTable;
    int rows;
    int cols;
    //building ancestor table --n*log(n)
    void createAT(int n){
        rows=n;
        cols=log2(n)+1;
        ancestorTable.resize(rows, vector<int>(cols, -1));
        //filling the immidiate parent of each node
        for(int node=0; node<rows; node++){
            ancestorTable[node][0]=parent[node];
        }
        
        for(int j=1; j<cols; j++){
            for(int node=0; node<rows; node++){
                if(ancestorTable[node][j-1] != -1){
                    ancestorTable[node][j]=ancestorTable[ancestorTable[node][j-1]][j-1];
                }
            }
        }

    }

    //find kth ancestor --log(n)
    int getAncestor(int node, int k){
        for(int j=0; j<cols; j++){
            if(k &(1<<j)){
                node=ancestorTable[node][j]; 
            }
            if(node==-1)    return -1; //edge case
        }
        return node;
    }

    //find LCA --log(n)
    int LCA(int u, int v, vector<int>& levelOfEachNode){
        int depth_of_u=levelOfEachNode[u];
        int depth_of_v=levelOfEachNode[v];
        int diff=abs(depth_of_u-depth_of_v);
        if(depth_of_v>depth_of_u){
            swap(u, v);
        }
        u=getAncestor(u, diff);
        if(u==v)    return u; /*edge case if 1   lca(2, 3)=2 but return 1 if not handled
                                            /  \
                                           2    5
                                          /    /  \
                                        3     6    7 */
        for(int j=cols-1; j>=0; j--){
            if(ancestorTable[u][j] == -1) continue;
            if(ancestorTable[u][j] != ancestorTable[v][j]){
                u=ancestorTable[u][j];
                v=ancestorTable[v][j];
            }
        }
        return ancestorTable[u][0];
    }

    //Process Each query Q*log(n)
    vector<int> processQuery(vector<int>& levelOfEachNode, vector<vector<int>>& queries){
        vector<int> res;
        for(vector<int>& query: queries){
            int src=query[0]-1;
            int des=query[1]-1;

            int lca=LCA(src, des, levelOfEachNode);
            
            int edgesBetweenNode=levelOfEachNode[src]+levelOfEachNode[des]-2*levelOfEachNode[lca];
            int totalways=edgesBetweenNode==0 ? 0 : modPow(2, edgesBetweenNode-1);

            res.push_back(totalways);
        }
        return res;
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n=edges.size();
        int V=n+1;
        unordered_map<int, vector<int>> adj;
        //creating adj list o(n)
        for(vector<int>& edge: edges){
            int u=edge[0]-1;
            int v=edge[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(V, false); //O(n)
        vector<int> levelOfEachNode(V, 0); //O(n)
        parent.resize(V); //O(n)
        
        bfs(0, visited, levelOfEachNode, adj); //O(n)
        createAT(V); //O(n*log(n))
         
        return processQuery(levelOfEachNode, queries);
    }
};