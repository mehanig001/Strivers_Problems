class Solution {
private:
    void bfs(vector<vector<int>>& adj,int n, int m, int &time, queue<pair<int,int>> &q){
 
      
        while(!q.empty()){
            int N = q.size();
            int deltaRow[] = {-1,0,1,0};
            int deltaCol[] = {0,1,0,-1};
            for(int j = 0; j < N; j++){
                pair<int,int> tp = q.front();
                q.pop();
                int row = tp.first, col = tp.second;
                // cout<<row<<" "<<col<<endl;
                for(int i = 0; i < 4; i++){
                    int newrow = row + deltaRow[i];
                    int newcol = col + deltaCol[i];
                    if(newrow < 0 || newrow > n-1 || newcol < 0 || newcol > m-1){
                        continue;
                    }
                    if(adj[newrow][newcol] == 1){
                        adj[newrow][newcol] = 2;
                        q.push({newrow,newcol});
                    }
                }
            }
            time++;
        }
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> adj = grid;
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(adj[i][j] == 2){  
                    q.push({i,j});
                }
            }
        }

        bfs(adj, n, m, time, q);

        for(auto vc : adj){
            for(auto val :vc){
                if(val == 1)return -1;
            }
        }

        return max(0,time-1);
    }
};