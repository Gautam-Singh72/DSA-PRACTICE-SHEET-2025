class MagicDictionary {
public:
    vector<string> words;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        words=dictionary;
    }
    
    bool search(string searchWord) {
        int n=words.size();
        int m=searchWord.size();
        for(int i=0; i<n; i++){
            if(words[i].size() == m){
                int count=0;
                for(int j=0; j<words[i].size(); j++){
                    if(words[i][j] != searchWord[j]){
                        count++;
                    }
                }
                if(count==1)    return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */