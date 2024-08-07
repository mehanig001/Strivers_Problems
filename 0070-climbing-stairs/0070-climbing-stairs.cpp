class Solution {
public:
    int solve(int n,int dp[]) {

        if(n==2||n==1 )return n;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=solve(n-1,dp)+solve(n-2,dp);
        
    }
    int climbStairs(int n) {
        int dp[n+1];
        for(int i=0;i<n+1;i++){
            dp[i]=-1;
        }
        return solve(n,dp);
        
    }
};