class Solution {
public:
    static bool compare(const pair<int, string>& a, const pair<int, string>& b){
        if(a.first > b.first) return true;
        if(a.first == b.first && a.second < b.second)   return true;

        return false;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;

        for(string &word: words){
            mp[word]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(&compare)> pq(compare);
        for(auto it=mp.begin(); it!=mp.end(); it++){
            if(k){
                pq.push({it->second, it->first});
                k--;
            }else{
                int freq=it->second;
                string word=it->first;
                if(freq > pq.top().first || (freq == pq.top().first && word < pq.top().second)){
                    pq.pop();
                    pq.push({freq, word});
                }
            }
        }
        vector<string> res;
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            res.push_back(p.second);
        }
        reverse(res.begin(), res.end());

        return res;
    }
};