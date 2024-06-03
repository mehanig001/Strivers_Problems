class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int> &visited, int n){
        visited[node] = 1;
        for(auto i : adj[node]){
            if(!visited[i]){
                dfs(i,adj,visited,n);
                }
            }       
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> isConnectedadj[n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] && i != j){
                    isConnectedadj[i].push_back(j);
                }
            }
        }

        int ans = 0;

        vector<int> visited(n,0);
       
        for(int i = 0; i < n; i++){
            if(visited[i] == 1)continue;
           
            ans++;
            dfs(i,isConnectedadj,visited,n);
        }

        return ans;
    }
};