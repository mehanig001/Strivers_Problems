class Solution {

private: 
    int timer = 0;

    void dfs(int node, int parent, vector<int> adj[], vector<int> &visited, vector<int> &tin, vector<int> &lowt, vector<vector<int>> &ans){

        visited[node] = 1;
        tin[node] = timer;
        lowt[node] = timer;

        timer++;

        for(auto it : adj[node]){
            if(it == parent)continue;
            if(!visited[it]){
                dfs(it,node,adj,visited,tin,lowt,ans);
                lowt[node] = min(lowt[it], lowt[node]);
                if(lowt[it] > tin[node]){
                    ans.push_back({it,node});
                }
            }
            else{
                lowt[node] = min(lowt[node], lowt[it]);
            }
        }

    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>ans;  //bridges problem right

        vector<int> visited(n,0);
        vector<int> tin(n,0); //time of insertion
        vector<int> lowt(n,0);  //lowest time of insertion across all adjacent edges except parent

        //making adjList
        vector<int> adj[n];
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        int parent = -1;

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i,parent,adj,visited,tin,lowt, ans);
            }
        }

        return ans;

    }
};