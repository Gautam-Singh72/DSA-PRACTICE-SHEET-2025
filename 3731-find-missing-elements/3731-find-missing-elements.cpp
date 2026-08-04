class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int smallest=*min_element(nums.begin(), nums.end());
        int largest=*max_element(nums.begin(), nums.end());

        vector<int> res;
        for(int i=smallest+1; i<largest; i++){
            if(!s.contains(i)){
                res.push_back(i);
            }
        }

        return res;
    }
};