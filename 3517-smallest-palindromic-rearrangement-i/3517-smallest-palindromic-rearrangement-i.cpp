class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        for(char &ch: s){
            freq[ch-'a']++;
        }

        string start; string end;
        for(int i=0; i<26; i++){
            if(freq[i]){
                int count=freq[i]/2;
                freq[i]=freq[i]%2;
                while(count){
                    char ch=i+'a';
                    start+=ch;
                    end+=ch;
                    count--;
                }
            }
        }

        for(int i=0; i<26; i++){
            if(freq[i]){
                char ch=i+'a';
                start+=ch;
            }
        }
        reverse(end.begin(), end.end());
       

        return start+end;
    }
};