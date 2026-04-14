class Solution {
public:
    long long solve(int i, int j, vector<int>& robots, vector<int>& positions, vector<vector<long long>>& dp){
        if(i>=robots.size())    return 0;
        if(j>=positions.size())  return 1e12;
        if(dp[i][j]!=-1)    return dp[i][j];

        long long take=abs(robots[i]-positions[j])+solve(i+1, j+1, robots, positions, dp);
        long long skip=solve(i, j+1, robots, positions, dp);

        return dp[i][j]=min(take, skip);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int>positions;
        for(vector<int> arr: factory){
            int pos=arr[0];
            int limit=arr[1];

            for(int i=0; i<limit; i++){
                positions.push_back(pos);
            }
        }
        int n=robot.size();
        int m=positions.size();
        vector<vector<long long>> dp(n, vector<long long>(m, -1));

        return solve(0, 0, robot, positions, dp);

    }
};