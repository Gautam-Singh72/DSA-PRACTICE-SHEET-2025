class Solution {
public:
    //count pairs whose sum is divisible by t
    int countPairs(int t, vector<int>& arr) {
    vector<int> freq(t, 0);
    int count = 0;

    for (int time : arr) {
        int rem = time % t;
        int complement = (t - rem);
        if(complement==t){
            count+=freq[0];
        }
        else{
            count += freq[complement];
        }
        freq[rem]++;
    }

    return count;
}
    int numPairsDivisibleBy60(vector<int>& time) {
        
        return countPairs(60, time);
    }
};