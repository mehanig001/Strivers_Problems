class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int> &visited, int n){
        visited[node] = 1;
        for(int i = 0; i < n; i++){
            if(!visited[i])
                if(adj[node][i]){
                    dfs(i,adj,visited,n);
                }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        vector<int> visited(n,0);
      
        for(int i = 0; i < n; i++){
            if(visited[i] == 1)continue;
            ans++;
            dfs(i,isConnected,visited,n);
        }


        return ans;
    }
};