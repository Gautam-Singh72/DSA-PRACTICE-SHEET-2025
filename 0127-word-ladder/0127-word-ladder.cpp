class Solution {
public:
    unordered_set<string> s;
    int bfs(string &beginWord, string &endWord){
        queue<string> q;
        q.push(beginWord);

        int level=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                string word=q.front();
                q.pop();

                for(int i=0; i<word.size(); i++){
                    char currChar=word[i];
                    for(int j=0; j<26; j++){
                        char ch='a'+j;
                        word[i]=ch;
                        if(s.find(word) != s.end()){
                            if(word == endWord) return level+1;
                            q.push(word);
                            s.erase(word);
                        }
                    }
                    word[i]=currChar;
                }
            }
            level++;
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(string &word: wordList){
            s.insert(word);
        }
        return bfs(beginWord, endWord);
    }
};