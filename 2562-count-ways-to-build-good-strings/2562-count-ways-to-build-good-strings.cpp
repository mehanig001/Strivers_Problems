int mod = 1e9+7;
class Solution {
public:
    int f(int len, int low, int high, int zero, int one, vector<int> &dp){
        if(len > high){
            return 0;
        }
        if(dp[len] != -1)return dp[len];
       
        int add = 0;
        if(len >= low && len <= high){
            add = 1;
        }
        int takeZero = f(len+zero, low, high, zero, one, dp);
        int takeOne = f(len+one, low, high, zero, one, dp);

        int ans = (takeZero + takeOne)%mod;
        return dp[len] = (ans + add)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        int len = 0;
        vector<int> dp(high+1, -1);
        return f(len, low, high, zero, one, dp);
    }
};