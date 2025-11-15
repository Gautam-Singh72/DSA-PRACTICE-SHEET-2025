class Solution {
public:
    struct Comp {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            return a.second < b.second;  // max-heap by second value
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> p;
        unordered_map<int, int> mpp;
        for(int &num: nums){
            mpp[num]++;
        }
        for(auto &it: mpp){
            p.push({it.first, it.second});
        }
        vector<int> ans;
        while(k-- && !p.empty()){
            ans.push_back(p.top().first);
            p.pop();
        }
        return ans;
    }
};