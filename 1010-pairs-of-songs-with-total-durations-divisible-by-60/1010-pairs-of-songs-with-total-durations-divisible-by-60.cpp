class Solution {
public:
    int countPairs(vector<int>& arr) {
    vector<int> freq(60, 0);
    int count = 0;

    for (int time : arr) {
        int rem = time % 60;
        int complement = (60 - rem);
        if(complement==60){
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
        
        return countPairs(time);
    }
};