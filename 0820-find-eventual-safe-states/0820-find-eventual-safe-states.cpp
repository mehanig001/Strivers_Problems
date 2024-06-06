class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //Another aproach other than path visited and dfs
        //Using topoSort

        int n = graph.size();
        vector<int> adj[n];
        //adding edges in reverse order
        for(int i = 0; i < n; i++){
            for(int j = 0; j < graph[i].size(); j++){
                adj[graph[i][j]].push_back(i);
            }
        }

        vector<int> indegree(n);
        for(int i = 0; i < n; i++){
            for(auto val : adj[i]){
                indegree[val]++;
            }
        }

        queue<int> q;
        vector<int> topo;

        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int tp = q.front();
            q.pop();
            topo.push_back(tp);
            for(auto val : adj[tp]){
                indegree[val]--;
                if(indegree[val] == 0){
                    q.push(val);
                }
            }
        }
        sort(topo.begin(), topo.end());
        return topo;
    }
};