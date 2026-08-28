class Solution {
public:
    string res;
    bool solve(int i, string &curr, bool greater, string &target, vector<int>& count){
        if(i==target.size()){
            if(greater){
                res=curr;
                return true;
            }
            return false;
        }

        for(char ch='a'; ch<='z'; ch++){
            if(count[ch-'a']==0)    continue;

            if(!greater && ch<target[i]) continue;

            bool isGreater= greater || ch>target[i];
            curr.push_back(ch);
            count[ch-'a']--;

            if(solve(i+1, curr, isGreater, target, count)){
                return true;
            }
            curr.pop_back();
            count[ch-'a']++;
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26);
        for(char &ch: s){
            count[ch-'a']++;
        }
        string curr="";
        solve(0, curr, false, target, count);

        return res;
    }
};