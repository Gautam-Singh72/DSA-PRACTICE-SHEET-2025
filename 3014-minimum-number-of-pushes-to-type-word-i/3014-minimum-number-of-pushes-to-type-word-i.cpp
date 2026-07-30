class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int m=n/8;
        int res=4*m*(m+1);

        res+=(n%8)*((m+1));

        return res;
    }
};