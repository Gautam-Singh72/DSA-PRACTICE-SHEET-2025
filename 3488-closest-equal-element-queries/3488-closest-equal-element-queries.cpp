class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        int m = queries.size();
        for (int i = 0; i < m; i++) {
            int idx = queries[i];
            int val = nums[idx];
            if (mp[val].size() == 1) {
                ans.push_back(-1);
                continue;
            }
            int indexOf_idx = lower_bound(mp[val].begin(), mp[val].end(), idx)-mp[val].begin();
            int size = mp[val].size();
            int right = mp[val][(indexOf_idx + 1) % size];
            int right_d = abs(mp[val][indexOf_idx] - right);
            int circular_right = (n - right_d);
            int left = mp[val][(indexOf_idx - 1 + size) % size];
            int left_d = abs(mp[val][indexOf_idx] - left);
            int circular_left = (n - left_d);
            ans.push_back(min({left_d, right_d, circular_left, circular_right}));
        }

        return ans;
    }
};