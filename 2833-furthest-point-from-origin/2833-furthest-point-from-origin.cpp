class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n=moves.size();
        int extra=0;
        int left=0; int right=0;
        for(int i=0; i<n; i++){
            if(moves[i]=='L'){
                left++;
            }else if(moves[i]=='R'){
                right++;
            }else{
                extra++;
            }
        }
        return abs(right-left)+extra;
    }
};