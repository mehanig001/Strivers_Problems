class DSU{
    vector<int> parent, size;
    public:
        DSU(int n){
            parent.resize(n+1, 0);
            size.resize(n+1, 1);
            for(int i = 0; i < n+1; i++)parent[i] = i;
        }

        int findUltParent(int node){
            if(parent[node] == node)return node;
            return parent[node] = findUltParent(parent[node]);
        }
        
        void unionBySize(int u, int v){
            int ultp_u = findUltParent(u);
            int ultp_v = findUltParent(v);
            if(size[ultp_u] >= size[ultp_v]){
                parent[ultp_v] = ultp_u;
                // size[ultp_u] += size[ultp_v];
            }
            else{
                parent[ultp_u] = ultp_v;
                // size[ultp_v] += size[ultp_u];
            }
        }
};
class Solution {
public:
    int dfsWithAnd(vector<pair<int,int>> adj[], int i, vector<int> &visited){
        visited[i] = 1;
        int ans = (1<<30)-1;
        for(auto it : adj[i]){
            if (!visited[it.first]) {
                // AND with both current edge weight and result from recursion
                int childResult = dfsWithAnd(adj, it.first, visited);
                ans &= it.second;
                ans &= childResult;
            }
            else {
                // Even if the node is already visited, consider the current edge weight
                ans &= it.second;
            }
        }
        return ans;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU ds(n);
        for(auto it : edges){
            ds.unionBySize(it[0], it[1]);
        }

        map<int, int> mp;
        vector<pair<int,int>> adj[n];
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<int> visited(n, 0);
        for(int i = 0; i < n; i++){
            cout<<ds.findUltParent(i)<<" ";
            int ultp_i = ds.findUltParent(i);
            if(mp.find(ultp_i) == mp.end()){
                mp[ultp_i] = dfsWithAnd(adj, ultp_i, visited);
            }
        }

        vector<int> ans;
        for(auto it : query){
            int u = ds.findUltParent(it[0]);
            int v = ds.findUltParent(it[1]);
            if(u != v)ans.push_back(-1);
            else ans.push_back(mp[u]);
        }

        return ans;
    }
};