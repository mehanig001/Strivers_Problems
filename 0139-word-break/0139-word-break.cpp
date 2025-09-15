class Solution {
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        string curr = "";
        vector<bool> dp(s.size()+1, 0);
        dp[0] = 1;
        for(int i = 0; i <= s.size(); i++){
            for(auto &w : wordDict){
                int idx = i-w.size();
                if(idx >= 0 && dp[idx] && (s.substr(idx, w.size()) == w)){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};