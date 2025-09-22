#define pii pair<int, pair<int,int>>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, {0, src}});
        int ans = 1e9;
        vector<int> dist(n+1, 1e9);
        vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
        for(auto &it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        while(!pq.empty()){
            auto tp = pq.top();
            pq.pop();
            int stps = tp.first;
            int cst = tp.second.first;
            int node = tp.second.second;
            if(stps > k+1)break;
            if(node == dst){
                ans = min(ans, cst);
            }

            for(auto &it : adj[node]){
                auto adjNode = it.first;
                auto edgeWt = it.second;

                if(dist[adjNode] > cst + edgeWt){
                    dist[adjNode] = cst + edgeWt;
                    pq.push({stps+1, {dist[adjNode], adjNode}});
                }
            }
        }
        return (ans == 1e9) ? -1 : ans;  
    }
};