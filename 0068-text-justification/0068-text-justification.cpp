class Solution {
public:
    string makeLine(int i, int j, int space, int spaceLeft, int maxWidth, vector<string>& words){
        string line=words[i];
        i++;
        while(i <= j){
            for(int k=0; k<space; k++){
                line+=' ';
            }
            if(spaceLeft){
                line+=' ';
                spaceLeft--;
            }
            line+=words[i];
            i++;
        }
        while(line.size() < maxWidth){
            line+=' ';
        }
        return line;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n=words.size();

        int i=0;
        vector<string> res;
        while(i<n){
            int space=0; int len=words[i].size();
            int j=i+1;
            while(j<n && (len + space + words[j].size()+1   <= maxWidth)){
                space++;
                len+=words[j].size();
                j++;
            }
            int remainingSpace=maxWidth-(len+space);
            int extraSpace=(space==0) ? 0: (remainingSpace)/space;
            int spaceLeft=(space==0) ? 0: remainingSpace % space;
            if(j==n){
                extraSpace=0;
                spaceLeft=0;
            }
            string line=makeLine(i, j-1, extraSpace+1, spaceLeft, maxWidth, words);
            res.push_back(line);
            i=j;
        }

        return res;
    }
};