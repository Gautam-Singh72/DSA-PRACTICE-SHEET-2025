class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        if(words[startIndex]==target)   return 0;
        int n=words.size();
        int prevIndex=(startIndex-1+n)%n;
        int nextIndex=(startIndex+1)%n;
        int dis=1;
        //runs O(N) times 
        while(prevIndex!=startIndex){
            if(words[prevIndex]==target || words[nextIndex]==target)    return dis;

            dis++;
            prevIndex=(prevIndex-1+n)%n;
            nextIndex=(nextIndex+1)%n;
        }

        return -1;
    }
};