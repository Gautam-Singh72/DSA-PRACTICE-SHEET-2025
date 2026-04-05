class Solution {
public:
    bool judgeCircle(string moves) {
        int leftMove=0, rightMove=0;
        int upMove=0, downMove=0;
        for(char ch : moves){
            if(ch=='L') leftMove++;
            else if(ch=='R')    rightMove++;
            else if(ch=='U')    upMove++;
            else    downMove++;
        }
        return leftMove==rightMove && upMove==downMove;
    }
};