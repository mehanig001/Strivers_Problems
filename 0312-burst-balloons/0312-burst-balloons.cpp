class Solution {
private:
    int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        if(i > j)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int ans = 0;


        for(int k = i; k <= j; k++){
            int cost = (nums[i-1] * nums[k] * nums[j+1] )+ 
                            f(i, k-1, nums, dp) + f(k+1, j, nums, dp);

            ans = max(ans, cost);
        }

        return dp[i][j] = ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        v.push_back(1);
        for(auto val : nums)v.push_back(val);
        v.push_back(1);

        vector<vector<int>> dp(n+3, vector<int> (n+3, -1));
        return f(1,n, v, dp);
    }
};