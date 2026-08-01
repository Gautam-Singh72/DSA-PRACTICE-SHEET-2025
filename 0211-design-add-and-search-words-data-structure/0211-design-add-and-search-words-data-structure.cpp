class WordDictionary {
public:
    struct trieNode{
        bool isEndOfWord;
        trieNode* child[26];
    };

    trieNode* getNode(){
        trieNode* newnode=new trieNode();
        newnode->isEndOfWord=false;
        for(int i=0; i<26; i++){
            newnode->child[i]=nullptr;
        }

        return newnode;
    }

    trieNode* root;
    WordDictionary() {
        root=getNode();
    }
    
    void addWord(string word) {
        trieNode* crawler=root;
        for(char &ch: word){
            if(crawler->child[ch-'a']==nullptr){
                crawler->child[ch-'a']=getNode();
            }
            crawler=crawler->child[ch-'a'];
        }
        crawler->isEndOfWord=true;
    }
    bool find(int idx, trieNode* crawler, string &word){
        int n=word.size();
        if(idx==n ){
            return crawler->isEndOfWord==true;
        }    

        for(int i=idx; i<n; i++){
            char ch=word[i];
            if(ch=='.'){
                for(int j=0; j<26; j++){
                    if(crawler->child[j]){
                        if(find(i+1, crawler->child[j], word)){
                            return true;
                        }
                    }
                }
                return false;
            }else{
                if(crawler->child[ch-'a']==nullptr){
                    return false;
                }
                crawler=crawler->child[ch-'a'];
            }
        }
        return crawler->isEndOfWord==true;
    }
    
    bool search(string word) {
        
        return find(0, root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */