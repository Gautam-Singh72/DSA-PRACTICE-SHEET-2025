class Solution {
public:
    int dx[4]={-1, 0, 1, 0}; int dy[4]={0, -1, 0, 1};
    bool isValid(int i, int j, int n){
        return i>=0 && i<n && j>=0 && j<n;
    }
    int solve(int i, int j, int idx, int n, string s, vector<vector<vector<int>>>& dp){
        // if(i<0 || i>=n || j<0 || j>=n)  return 0;
        if(idx>=s.size())   return 0;
        if(dp[i][j][idx] != -1) return dp[i][j][idx];
        
        int r, c;
        if(s[idx]=='U') r=i+dx[0], c=j+dy[0];
        else if(s[idx]=='L')    r=i+dx[1], c=j+dy[1];
        else if(s[idx]=='D')    r=i+dx[2], c=j+dy[2];
        else    r=i+dx[3], c=j+dy[3];
        if(isValid(r, c, n)){
            return dp[i][j][idx]=1+solve(r, c, idx+1, n, s, dp);
        }

        return dp[i][j][idx]=0;
    }
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int startRow=startPos[0];
        int startCol=startPos[1];
        vector<int> ans;
        int m=s.size();
        for(int i=0; i<m; i++){
            int count=0;
            int r=startRow, c=startCol;
            for(int j=i; j<m; j++){
                if(s[j]=='U') r+=dx[0], c+=dy[0];
                else if(s[j]=='L')    r+=dx[1], c+=dy[1];
                else if(s[j]=='D')    r+=dx[2], c+=dy[2];
                else    r+=dx[3], c+=dy[3];

                if(isValid(r, c, n))    count++;
                else    break;
            }
            ans.push_back(count);
        }

        return ans;
    }
};