class Solution {
private:
    int dfs(int node, int parent, vector<int> adj[], vector<int> &values, int k, int &ct){
        int sum = values[node] % k;

        for(auto it : adj[node]){
            if(it != parent){
                sum = (sum +  dfs(it, node, adj, values, k, ct)) % k;
            }
        }
        if(sum == 0)ct++;
        return sum;
    }
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int> adj[n];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int ct = 0;
        dfs(0, -1, adj, values, k, ct);
        return ct;
    }
};