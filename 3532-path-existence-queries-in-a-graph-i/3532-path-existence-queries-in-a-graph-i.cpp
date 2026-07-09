class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int binarySearch(int s, int e, int currNode, vector<int>& nums, int &diff){
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;

            if(nums[mid]-currNode<= diff){
                ans=mid;
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return ans;
    }
    void Union(int x, int y){

        int parent_x=find(x);
        int parent_y=find(y);
        if(parent_x == parent_y)    return;

        if(rank[parent_x] > rank[parent_y]){
            parent[parent_y]=parent_x;
        }else if(rank[parent_x] < rank[parent_y]){
            parent[parent_x]=parent_y;
        }else{
            parent[parent_y]=parent_x;
            rank[parent_x]++;
        }

    }
    int find(int i){
        if(parent[i]==i)    return i;

        return parent[i]=find(parent[i]);
    }
    void findEdges(vector<int>& nums, int &diff){
        int n=nums.size();
        int i=0;
        while(i<n){

            int idx=binarySearch(i+1, n-1, nums[i], nums, diff);
            if(idx==-1){
                i++;
                continue;
            }
            for(int j=i+1; j<=idx; j++){
                Union(i, j);
            }
            i=idx;
        }
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n);
        rank.resize(n);
        for(int i=0; i<n; i++){
            parent[i]=i;
            rank[i]=1;
        }
        findEdges(nums, maxDiff);

        //process each query
        vector<bool> res;
        for(vector<int>& query: queries){
            int u=query[0];
            int v=query[1];

            int parent_u=find(u);
            int parent_v=find(v);
            if(parent_u==parent_v){
                res.push_back(true);
                continue;
            }
            res.push_back(false);
        }

        return res;
    }
};