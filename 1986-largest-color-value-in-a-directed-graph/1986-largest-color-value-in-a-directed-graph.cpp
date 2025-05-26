class Solution {
public:
    bool hasCycle = false;

    vector<vector<int>> dp;

    vector<int> dfs(int node, vector<vector<int>> &adj, string &colors, vector<bool> &vis, vector<bool> &inStack) {
        if (hasCycle) return vector<int>(26, 0);
        if (vis[node]) return dp[node];

        vis[node] = true;
        inStack[node] = true;

        vector<int> cnt(26, 0);
        for (int nei : adj[node]) {
            if (inStack[nei]) {
                hasCycle = true;
                return cnt;
            }

            vector<int> child = dfs(nei, adj, colors, vis, inStack);
            for (int c = 0; c < 26; c++) {
                cnt[c] = max(cnt[c], child[c]);
            }
        }

        cnt[colors[node] - 'a']++;
        inStack[node] = false;
        dp[node] = cnt;
        return cnt;
    }

    int largestPathValue(string colors, vector<vector<int>> &edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        dp.assign(n, vector<int>(26, 0));
        vector<bool> vis(n, false), inStack(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> curr = dfs(i, adj, colors, vis, inStack);
                for (int c = 0; c < 26; c++) {
                    ans = max(ans, curr[c]);
                }
            }
        }

        return hasCycle ? -1 : ans;
    }
};
