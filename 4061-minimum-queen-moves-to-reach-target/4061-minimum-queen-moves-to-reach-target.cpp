class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {

        int x=source[0];
        int y=source[1];

        int t_x=target[0];
        int t_y=target[1];

        if(x==t_x && y==t_y) return 0;

        if(x==t_x || y==t_y) return 1;

        while(x<=8 && y>=1){
            if(x==t_x && y==t_y) return 1;

            x++;
            y--;
        }

         x=source[0];
         y=source[1];
        while(x<=8 && y<=8){
            if(x==t_x && y==t_y) return 1;

            x++; y++;
        }

        x=source[0];
        y=source[1];
        while(x>=1 && y>=1){
            if(x==t_x && y==t_y) return 1;

            x--;
            y--;
        }

        x=source[0];
         y=source[1];
        while(x>=1 && y<=8){
            if(x==t_x && y==t_y) return 1;

            x--;
            y++;
        }

        return 2;
    }
};