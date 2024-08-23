class Solution {
private:
    int f(int i, int k, vector<int> &prices, bool flag, vector<vector<vector<int>>> &dp){
        int n = prices.size();
        if(i == n-1){
            if(k >= 1 && !flag){
                return prices[n-1];
            }
            return 0;
        }
        if(dp[i][k][flag] != -1)return dp[i][k][flag];
        int buy = 0;
        if(k > 0 && flag){
            buy = prices[i] * -1 + f(i+1, k, prices, 0, dp);
            int notBuy = f(i+1, k, prices, 1, dp);

            buy = max(buy, notBuy);
        }
        int sell = 0;
        if(k >= 1 && !flag){
            sell = prices[i] + f(i+1, k-1, prices, 1, dp);
            int notSell = f(i+1, k, prices, 0, dp);
            sell = max(sell, notSell);
        }

        return dp[i][k][flag] = max(buy, sell);
    }
public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> ((k+1), vector<int> (2, -1)));

        return f(0, k, prices, 1, dp);
    }
};