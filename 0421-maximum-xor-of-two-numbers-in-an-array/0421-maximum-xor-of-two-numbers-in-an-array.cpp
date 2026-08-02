class Solution {
public:
    struct trieNode{
        trieNode* child[2];
        int num;
    };

    trieNode* getNode(){
        trieNode* newnode=new trieNode();
        
        for(int i=0; i<2; i++){
            newnode->child[i]=nullptr;
        }
        newnode->num=-1;

        return newnode;
    }
    void insert(trieNode* root, int num){
        trieNode* crawler=root;

        for(int i=31; i>=0; i--){
            int bit=((1<<i) & num ) != 0;
            if(crawler->child[bit]==nullptr){
                crawler->child[bit]=getNode();
            }
            crawler=crawler->child[bit];
        }
        crawler->num=num;
    }
    int find(trieNode* root, int num){
        trieNode* crawler=root;

        for(int i=31; i>=0; i--){
            int bit=((1<<i) & num ) != 0;
            int togle=bit ^ 1;
            if(crawler->child[togle]==nullptr){
                crawler=crawler->child[bit];
                continue;
            }
            crawler=crawler->child[togle];
        }
        return crawler->num;
    }
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        trieNode* root=getNode();
        for(int num: nums){
            insert(root, num);
        }

        int res=0;
        for(int num: nums){
            int second=find(root, num);
            res=max(res, num^second);
        }

        return res;
    }
};