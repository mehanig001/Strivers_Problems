class Solution {
private:
    int f(int i, int j, vector<vector<int>> &v, vector<vector<int>> &dp){
        if(i == 0 && j == 0 && v[i][j] == 0)return 1;
        if(i < 0 || j < 0)return 0;
        if(v[i][j] == 1)return 0;
        if(dp[i][j] != -1)return dp[i][j];

        int left =  f(i-1, j, v, dp);
        int up = f(i, j-1, v, dp);

        return dp[i][j] = up + left;

    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> dp(n+1, vector<int> (m+1,-1));

        return f(n-1, m-1, obstacleGrid, dp);
    }
};