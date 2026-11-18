class Solution {
public:
    int minChanges(string s) {
        int n=s.size();
        if(n==2 && s[0]!=s[1])  return 1;

        int size=2;
        int i=0; int j=0;
        int count_of_one=0;
        int count_of_zero=0;
        int res=0;
        while(j<n){
            count_of_one+=s[j]=='1' ? 1 : 0;
            count_of_zero+=s[j]=='0' ? 1 : 0;

            if(j-i+1==size){
                res+=min(count_of_one, count_of_zero);
                count_of_one=0;
                count_of_zero=0;
                i=j+1;
            }
            j++;
        }

        return res;
    }
};