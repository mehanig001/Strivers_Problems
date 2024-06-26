class Solution {

int f(int i, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp){
    if(i == prices.size())return 0;
    if(cap == 0)return 0;

    if(dp[i][buy][cap] != -1)return dp[i][buy][cap];

    if(buy){
        return dp[i][buy][cap] = max(f(i+1,1,cap, prices, dp), -1*prices[i] + f(i+1, 0, cap, prices, dp));
    }
    else{
        return dp[i][buy][cap] = max(f(i+1,0,cap, prices, dp), prices[i] + f(i+1,1,cap-1, prices, dp));
    }
}

public:
     int maxProfit(vector<int>& prices){
        // Write your code here.
        //just like finding 1st maximum and second maximum 
        // return f(0,1,2,prices, dp);
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2, vector<int> (3,0)));

        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 2; cap > 0; cap--){

                    if(buy){
                        dp[i][buy][cap] = max(dp[i+1][1][cap], -1*prices[i] + dp[i+1][0][cap]);
                    }
                    else{
                        dp[i][buy][cap] = max(dp[i+1][0][cap], prices[i] + dp[i+1][1][cap-1]);
                    }    
                }
            }
        }

        return dp[0][1][2];
        
    }

};