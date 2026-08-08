class Solution {
public:
    int solve(int n){
        if(n<=1)    return 1;

        int count=0;
        for(int i=0; i<n; i++){
            int L=solve(i);
            int R=solve(n-i-1);
            count+=L*R;
        }

        return count;
    }
    int numTrees(int n) {
        return solve(n);
    }
};