class Solution {
public:
    bool isPathExist(int u, int v, vector<vector<int>> &adj, vector<int> &visited){
        visited[u] = 1;
        if(u == v)return true;
        for(auto it : adj[u]){
            if(!visited[it] && isPathExist(it, v, adj, visited))return true;
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites){
            adj[it[0]].push_back(it[1]);
        }

        for(auto it : queries){
            vector<int> visited(numCourses,0);
            ans.push_back(isPathExist(it[0], it[1], adj, visited));
        }
        return ans;
    }
};