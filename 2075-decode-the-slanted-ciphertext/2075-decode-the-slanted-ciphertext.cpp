class Solution {
public:
    //to push on github 
    string decodeCiphertext(string encodedText, int rows) {
        int n=encodedText.size();
        int col=n/rows;
        string ans="";
        int i=0, j=0;
        while(j<col){
            int r=i, c=j;
            while(r<rows && c<col){
                int idx=r*col+c;
                ans+=encodedText[idx];
                r++;
                c++;
            }
            j++;
        }
        int m=ans.size();
        int k=m-1;
        while(k>=0 && ans[k]==' '){
            ans.pop_back();
            k--;
        }
        return ans;
    }
};