class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        //lets find lcs of both
        int n = str1.size(), m = str2.size();

        vector<vector<int>> dp(n+1, vector<int> (m+1,0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        //now dp table is filled we will take the common char ones

        int i = n, j = m;
        string ans = "";

        while( i > 0 && j > 0){
            if(str1[i-1] == str2[j-1]){
                ans += str1[i-1];
                i--;
                j--;
            }
            else if(dp[i][j] == dp[i-1][j]){
                ans += str1[i-1];
                i--;
            }
            else{
                ans += str2[j-1];
                j--;
            }
        }

        while(i > 0){
            ans += str1[i-1];
            i--;
        }

        while(j > 0){
            ans += str2[j-1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;

    }
};