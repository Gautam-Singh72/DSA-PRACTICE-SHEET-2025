class Solution {
public:
    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    int maxVowels(string s, int k) {
        int n=s.size();

        int count=0, res=0;
        for(int i=0; i<k; i++){
            if(isVowel(s[i])){
                count++;
            }
        }
        res=max(res, count);
        int st=0, end=k;
        while(end<n){
            if(isVowel(s[st])){
                count--;
            }
            st++;

            if(isVowel(s[end])) count++;

            res=max(res, count);
            end++;
        }
        return res;
    }
};