class Solution {
private:
    int f(int i, int curr, int totalSum, int sum, vector<int> &v, vector<vector<int>> &dp){
        if(i < 0){
            int isTaraf = curr;
            int usTaraf = totalSum - curr;
            if((isTaraf - usTaraf == sum)){
                return 1;
            }
            else return 0;
        }
        if(dp[i][curr] != -1)return dp[i][curr];
        
        int take = f(i-1, curr + v[i], totalSum, sum, v, dp);
        int notTake = f(i-1, curr, totalSum, sum, v, dp);

        return dp[i][curr] = take + notTake;

    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(),0);
        vector<vector<int>> dp(nums.size(), vector<int> (totalSum + 1, -1));
        return f(nums.size()-1, 0, totalSum, target, nums, dp);
    }
};