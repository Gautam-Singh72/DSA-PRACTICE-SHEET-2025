class Solution {
public:
    unordered_map<int, vector<int>> adj;
    int height(int u){
        queue<int> q;
        q.push(u);

        int height=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int src=q.front();
                q.pop();

                for(int &v: adj[src]){
                    q.push(v);
                }
            }
            height++;
        }
        return height;
    }
    long long solve(int u, int &h, vector<int>& nums){
        
        queue<int> q;
        q.push(u);

        long long depth=1;
        long long sum=0;
        while(!q.empty()){
            int sz=q.size();

            while(sz--){
                int node=q.front();
                q.pop();
                for(int &v: adj[node]){ //push the neighbour nodes in queue
                    q.push(v);
                }

                long long value=nums[node];
                sum+=(value * (h-depth+1) );
                
            }
            depth++;
        }

        return sum;
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n=parent.size();
        if(n==1)    return nums[0];
        for(int i=1; i<n; i++){
            int u=parent[i];
            int v=i;
            adj[u].push_back(v);
        }

        int h=height(0);
        cout<<h<<endl;


        return solve(0, h, nums);
    }   
};