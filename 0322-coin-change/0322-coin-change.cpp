class Solution {
private:
    int f(int i, int sum, vector<int> &coins, vector<vector<int>> &dp){
        if(sum == 0)return 0;
        if(i == 0){
            if(sum % coins[i] == 0){
                return sum/coins[i];
            }
            else return 1e9;
        }

        if(dp[i][sum] != -1)return dp[i][sum];

        int take = 1e9;

        if(coins[i] <= sum){
            take = 1 + f(i, sum-coins[i], coins, dp);
        }

        int notTake = f(i-1, sum, coins, dp);

        return dp[i][sum] = min(take, notTake);

    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int> (amount+1, -1));

        int ans = f(n-1, amount, coins, dp);

        return (ans == 1e9) ? -1 : ans;
    }
};