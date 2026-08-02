class Solution {
public:
    struct trieNode{
        trieNode* child[2];
    };
    trieNode* getNode(){
        trieNode* newnode=new trieNode();
        for(int i=0; i<2; i++){
            newnode->child[i]=nullptr;
        }

        return newnode;
    }

    void insert(trieNode* root, int num){
        trieNode* crawler=root;

        for(int i=31; i>=0; i--){
            int bit=((num >> i) & 1) != 0;
            if(crawler->child[bit]==nullptr){
                crawler->child[bit]=getNode();
            }
            crawler=crawler->child[bit];
        }
        
    }
    int find(trieNode* root, int &num){
        trieNode* crawler=root;
        // if(crawler==nullptr)    return -1;
        int second=0;
        for(int i=31; i>=0; i--){
            int bit=((num >> i) & 1) != 0; //to follow rules of c++ and prevent compiler levl issue 
            int toggle=bit ^ 1;

            if(crawler->child[toggle]==nullptr){
                if(crawler->child[bit]==nullptr)    return -1;
                crawler=crawler->child[bit];
                if(bit) second+=pow(2, i);
            }else{
                crawler=crawler->child[toggle];
                if(toggle)  second+=pow(2, i);
            }
        }

        return second;
    }
    static bool compare(vector<int>& a, vector<int>& b){
        if(a[1] < b[1])   return true;

        return false;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int m=queries.size();
        trieNode* root=getNode();

        vector<int> res(m, -1);
        //to maintain the order of the queries in res;
        for(int i=0; i<m; i++){
            queries[i].push_back(i);
        }
        sort(nums.begin(), nums.end());
        sort(queries.begin(), queries.end(), compare);
        
        int idx=0;
        for(vector<int>& query: queries){
            int num=query[0];
            int maxi=query[1];
            int j=query[2];

            while(idx<n){
                if(nums[idx]>maxi)  break;

                insert(root, nums[idx]);
                idx++;
            }

            int second=find(root, num);
            if(second==-1)  continue;
            res[j]=(num ^ second);
        }

        return res;
    }
};