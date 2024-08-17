class Solution {
    int f(vector<int> &v, int i, int prev, vector<vector<int>> &dp){
        if(i == 0){
            if(prev == 1)return 0;
            else{
                return v[0];
            }
        }
        if(dp[i][prev] != -1)return dp[i][prev];

        int take = 0;
        if(prev != i+1){
            take = v[i] + f(v,i-1,i,dp);

        }
        int notTake = f(v,i-1,prev,dp);

        return dp[i][prev] = max(take, notTake);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+2, -1));
        return f(nums, n-1, n+1,dp);
    }
};