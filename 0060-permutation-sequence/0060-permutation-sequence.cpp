class Solution {
public:
    string getPermutation(int n, int k) {
        vector<string> arr;
        string temp = "";
        for (int i = 1; i <= 9; i++) {
            char ch = i + '0';
            temp += ch;
            arr.push_back(temp);
            cout<<temp<<endl;
        }
        while (k>1){
            next_permutation(arr[n-1].begin(), arr[n-1].end());
            k--;
        }
        return arr[n-1];
    }
};