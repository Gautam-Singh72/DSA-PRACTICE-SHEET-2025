class Solution {
public:
    static bool compare(pair<string, int>&a, pair<string, int>&b){
        if(a.second > b.second) return true;
        if(a.second == b.second && a.first < b.first)   return true;

        return false;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<pair<string, int>> res;
        unordered_map<string, int> mp;

        for(string &word: words){
            if(mp.count(word)){
                int idx=mp[word];
                res[idx].second+=1;
                continue;
            }
            res.push_back({word, 1});
            mp[word]=res.size()-1;
        }

        sort(res.begin(), res.end(), compare);
        vector<string> temp;
        for(int i=0; i<k; i++){
            temp.push_back(res[i].first);
        }

        return temp;
    }
};