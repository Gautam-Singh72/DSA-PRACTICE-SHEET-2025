class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        if(words[startIndex]==target) return  0;
        int prev_idx=(startIndex-1+n)%n;
        int next_idx=(startIndex+1)%n;
        int dis=1;
        while(prev_idx != startIndex && next_idx!=startIndex){
            if(words[prev_idx]==target)  return dis;
            if(words[next_idx]==target) return dis;

            dis++;
            prev_idx=(prev_idx-1+n)%n;
            next_idx=(next_idx+1)%n;
        }

        return -1;
    }
};