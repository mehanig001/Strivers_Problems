class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(int i = 0; i < flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}}); //stops, {node, dist}
        vector<int> dist(n+1, 1e9);
        dist[src] = 0;

        while(!q.empty()){
            auto pr = q.front();
            q.pop();
            int stops = pr.first;
            int node = pr.second.first;
            int dis = pr.second.second;

            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgeWt = it.second;

                if(stops <= k && dist[adjNode] > dis + edgeWt){
                    dist[adjNode] = dis + edgeWt;
                    q.push({stops+1, {adjNode, dist[adjNode]}});
                }
            }
        }

        for(auto val : dist)cout<<val<<" ";
        cout<<endl;

        return (dist[dst] == 1e9) ? -1 : dist[dst];
    }
};