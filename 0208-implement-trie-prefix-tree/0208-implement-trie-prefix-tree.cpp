class Trie {
public:
    struct trieNode{
        bool isEnd;
        trieNode* child[26];
    };
    

    trieNode* getNode(){
        trieNode* newnode=new trieNode();
        newnode->isEnd=false;
        for(int i=0; i<26; i++){
            newnode->child[i]=nullptr;
        }
        return newnode;
    }
    trieNode* root=nullptr;
    Trie() {
        root=getNode();
    }
    
    void insert(string word) {
        trieNode* crawler=root;
        for(char &ch: word){
            if(crawler->child[ch-'a'] == nullptr){
                crawler->child[ch-'a']=getNode();
            }
            crawler=crawler->child[ch-'a'];
        }
        crawler->isEnd=true;
    }
    
    bool search(string word) {
        trieNode* crawler=root;
        for(char &ch: word){
            if(crawler->child[ch-'a']==nullptr){
                return false;
            }
            crawler=crawler->child[ch-'a'];
        }
        return crawler->isEnd == true;
    }
    
    bool startsWith(string prefix) {
        trieNode* crawler=root;
        for(char &ch: prefix){
            if(crawler->child[ch-'a']==nullptr){
                return false;
            }
            crawler=crawler->child[ch-'a'];
        }
        return true;
    }
    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */