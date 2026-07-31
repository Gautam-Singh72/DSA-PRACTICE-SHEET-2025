class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for(char &ch: word){
            freq[ch-'a']++;
        }
        int res=0;
        int count=0;
        sort(freq.begin(), freq.end(), greater<int>());
        for(int i=0; i<26; i++){
            if(freq[i]){
                int cost=count/8+1;
                res+=freq[i]*cost;
                count++;
            }
        }

        return res;
    }
};