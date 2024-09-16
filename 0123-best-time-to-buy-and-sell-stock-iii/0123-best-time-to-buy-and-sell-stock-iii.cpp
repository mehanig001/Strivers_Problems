class Solution {
    int f(vector<int> &prices, int i, int k, int buy, vector<vector<vector<int>>> &dp){
        if(k == 0)return 0;
        if(i == prices.size()-1){
            if(buy == 0)return 0;
            else return prices.back();
        }
        if(dp[i][k][buy] != -1)return dp[i][k][buy];

        if(buy == 1){
            int sell = prices[i] + f(prices, i+1, k-1, 0, dp);
            int notSell = f(prices, i+1, k, 1, dp);
            return dp[i][k][buy] =  max(sell, notSell);
        }
        int by = -1*prices[i] + f(prices, i+1, k, 1, dp);
        int notBuy = f(prices, i+1, k, 0, dp);
        return dp[i][k][buy] = max(by, notBuy);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (3, vector<int> (2, -1)));
        return f(prices, 0, 2, 0, dp);
    }
};