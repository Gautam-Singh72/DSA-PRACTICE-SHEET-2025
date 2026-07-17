class Solution {
public:
    long long countPairs(int t, vector<int>& arr) {
    vector<int> freq(t, 0);
    long long count = 0;

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
    long long countCompleteDayPairs(vector<int>& hours) {
        
        return countPairs(24, hours);
    }
};