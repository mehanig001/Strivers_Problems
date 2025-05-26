class Solution {
private:
    bool dfs(int i, vector<bool> &visited, vector<bool> &pathVisited, vector<bool> &safeNodes, vector<vector<int>>& graph, int n){
        visited[i] = 1;
        pathVisited[i] = 1;
        safeNodes[i] = 0;

        for(auto val : graph[i]){

            if(!visited[val]){
                if(dfs(val,visited,pathVisited,safeNodes,graph,n)){
                    return true;
                }
            }
            else if(pathVisited[val]){
                    return true;
            }
        }
        
        pathVisited[i] = 0;
        safeNodes[i] = 1;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<bool> visited(n,0);
        vector<bool> pathVisited(n,0);
        vector<bool> safeNodes(n,0);

        for(int i = 0 ; i < n; i++){
            if(!visited[i]){
                dfs(i,visited,pathVisited,safeNodes,graph,n);
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(safeNodes[i]){
                ans.push_back(i);
            }
        }
        return ans;

    }
};