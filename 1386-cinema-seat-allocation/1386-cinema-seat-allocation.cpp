class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int, unordered_set<int>> mp;

        for(auto & reservedseat: reservedSeats){
            int row=reservedseat[0];
            int seat=reservedseat[1];

            mp[row].insert(seat);
        }

        int res=(n-mp.size())*2;
        for(auto &[row, bookedseat]: mp){
            auto isAvailable =[&](int seat){
                return bookedseat.find(seat)==bookedseat.end();
            };

            bool groupA=isAvailable(2) && isAvailable(3) && isAvailable(4) && isAvailable(5);
            bool groupB=isAvailable(4) && isAvailable(5) && isAvailable(6) && isAvailable(7);
            bool groupC=isAvailable(6) && isAvailable(7) && isAvailable(8) && isAvailable(9);

            if(groupA && groupC){
                res+=2;
            }else if(groupA || groupB || groupC){
                res+=1;
            }
        }

        return res;
    }
};