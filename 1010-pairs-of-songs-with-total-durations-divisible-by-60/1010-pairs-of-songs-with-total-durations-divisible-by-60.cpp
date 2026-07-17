class Solution {
public:
    //count pairs whose sum is divisible by t
    int countPairs(int t, vector<int>& arr) {
    vector<int> freq(t, 0);
    int count = 0;

    for (int time : arr) {
        int q = (time-1) / t+1;
        int diff = (60*q-time);
        
        count+=freq[diff];

        freq[time%60]++;
    }

    return count;
}
    int numPairsDivisibleBy60(vector<int>& time) {
        
        return countPairs(60, time);
    }
};