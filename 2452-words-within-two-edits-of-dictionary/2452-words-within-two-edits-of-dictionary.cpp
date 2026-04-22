class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;
        int n=queries[0].size();
        for(string& query: queries){
            for(string& word: dictionary){
                int i=n-1; int edits=0;
                while(i>=0){
                    if(query[i]!=word[i]) edits++;
                    i--;
                }
                if(edits<=2){
                    res.push_back(query);
                    break;
                }    
            }
        }
        return res;
    }
};