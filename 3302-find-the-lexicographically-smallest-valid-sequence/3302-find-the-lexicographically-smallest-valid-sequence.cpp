class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int> rightMatch(n);

        int i=n-1; int j=m-1;
        int count=0;
        while(i>=0 && j>=0){
            if(word1[i]==word2[j]){
                count++;
                rightMatch[i]=count;
                i--; j--;
            }else{
                rightMatch[i]=count;
                i--;
            }
        }
        while(i>=0){
            rightMatch[i]=count;
            i--;
        }

        i=0; j=0; bool changePower=true;
        vector<int> seq;
        while(i<n && j<m){
            if(word1[i]==word2[j]){
                seq.push_back(i);
                i++; j++;
            }else{
                if(changePower && i+1<n && rightMatch[i+1]>=m-j-1){
                    seq.push_back(i);
                    changePower=false;
                    i++; j++;
                }else{
                    i++;
                }
            }
        }
        if(j==m)    return seq;

        return {};
    }
};