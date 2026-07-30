class Solution {
public:
    //custom sorting (ascending by first and desc by second if first is same)
    static bool compare(vector<int> &a, vector<int>& b){
        if(a[0]<b[0])   return true;
        if(a[0]==b[0] && a[1]>b[1])   return true;

        return false;
    }
    //t.c-O(n*logn + n)=O(n*logn) and S.C-O(1) optimal
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end(), compare); //n*(logn)

        int lastElementIdx=intervals[0][1]; //O(1) space 
        int count=1; //non overlapping intervals count
        for(int j=1; j<n; j++){ //O(n)
            int start=intervals[j][0];
            int end=intervals[j][1];
            //start>=result.back()[0] since sorted no need of this condition
            if(end<=lastElementIdx){ //overlapped interval
                continue;
            }
            lastElementIdx=intervals[j][1]; //non overlapped interval
            count++;
        }
        return count;
    }
};