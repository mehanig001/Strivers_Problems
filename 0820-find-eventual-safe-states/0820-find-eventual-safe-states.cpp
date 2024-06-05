class Solution {
private:
    bool dfs(int i, vector<bool> &visited, vector<bool> &pathVisited, vector<bool> &isSafe, vector<vector<int>>& graph, int n){
        visited[i] = 1;
        pathVisited[i] = 1;
        isSafe[i] = 0;

        for(auto val : graph[i]){
            if(!visited[val]){
                if(dfs(val,visited,pathVisited,isSafe,graph,n))return true;
            }
            else if(pathVisited[val])return true;
        }

        pathVisited[i] = 0;
        isSafe[i] = 1;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<bool> visited(n,0);
        vector<bool> pathVisited(n,0);
        vector<bool> isSafe(n,0);
        
        for(int i = 0 ; i < n; i++){
            if(!visited[i]){
                dfs(i,visited,pathVisited,isSafe,graph, n);
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(isSafe[i])ans.push_back(i);
        }
        return ans;
    }
};