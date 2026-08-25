class Solution {
public:
    vector<string> board={"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
    int dx[4]={-1, 0, 1, 0}; int dy[4]={0, -1, 0, 1};

    char move[4]={'U', 'L', 'D', 'R'};
    bool isValid(int i, int j){
        if(i==5 && j>0) return false;
        if(i<0 || j<0 || i>5 || j>4){
            return false;
        }

        return true;
    }
    string solve(int i, int j, char target){
        queue<pair<pair<int, int>, string>> q;
        vector<vector<bool>> visited(6, vector<bool>(5, false));
        q.push({{i, j}, ""});
        visited[i][j]=true;

        while(!q.empty()){

            auto p=q.front();
            q.pop();
            if(board[p.first.first][p.first.second] == target){
                return p.second+"!"+to_string(p.first.first)+to_string(p.first.second);
            }

            for(int d=0; d<4; d++){
                char dir=move[d];
                int r=p.first.first+dx[d];
                int c=p.first.second+dy[d];
                string path=p.second;
                if(isValid(r, c) && !visited[r][c]){
                    q.push({{r, c}, path+dir});
                    visited[r][c]=true;
                }
            }
        }
        return "";
    }
    string alphabetBoardPath(string target) {
        int n=target.size();

        string res="";
        int r=0; int c=0;
        for(int i=0; i<n; i++){
            string temp=solve(r, c, target[i]);
            c=temp.back()-'0';
            temp.pop_back();
            r=temp.back()-'0';
            temp.pop_back();
            res+=temp;
        }
        return res;
    }
};