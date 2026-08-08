class MapSum {
public:
    struct trieNode{
        int val;
        trieNode* child[26];
    };
    trieNode* getNode(){
        trieNode* newnode=new trieNode();
        newnode->val=0;
        for(int i=0; i<26; i++){
            newnode->child[i]=nullptr;
        }

        return newnode;
    }
    trieNode* root;
    unordered_map<string, int> mp;
    MapSum() {
        root=getNode();
    }
    void insertInTrie(trieNode* root, string &word, int val){
        trieNode* crawler=root;

        for(char &ch: word){
            if(crawler->child[ch-'a']==nullptr){
                crawler->child[ch-'a']=getNode();
            }
            crawler=crawler->child[ch-'a'];
            crawler->val+=val;
        }
    }
    
    void insert(string key, int val) {
        if(mp.count(key)){
            int prevVal=mp[key];
            mp[key]=val;
            val=val-prevVal;
            insertInTrie(root, key, val);
            return;
        }
        insertInTrie(root, key, val);
        mp[key]=val;
    }
    
    int sum(string prefix) {
        trieNode* crawler=root;
        int sum=0;
        for(char &ch: prefix){
            if(crawler->child[ch-'a']==nullptr){
                return 0;
            }
            crawler=crawler->child[ch-'a'];
        }
        sum=crawler->val;

        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */