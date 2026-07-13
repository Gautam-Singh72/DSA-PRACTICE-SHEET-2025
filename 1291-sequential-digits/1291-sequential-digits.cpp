class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        for(int i=1; i<9; i++){
            q.push(i);
        }
        vector<int> res;
        while(!q.empty()){
            auto temp=q.front();
            q.pop();

            if(temp>high)   break;
            if(temp>=low){
                res.push_back(temp);
            }

            int lastDigit=temp%10;
            if(lastDigit==9)    continue;
            temp=temp*10+(lastDigit+1);
            q.push(temp);
        }

        return res;
    }
};