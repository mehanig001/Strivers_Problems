class Solution {
private:
    void bfs(queue<pair<int,int>> q, vector<vector<int>> &visited, vector<vector<int>>& grid, int n, int m){
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,-1,0,1};
        while(!q.empty()){

            int N = q.size();
            for(int i = 0; i < N; i++){
                auto pr = q.front();
                int row = pr.first;
                int col = pr.second;
                q.pop();

                for(int j = 0; j < 4; j++){
                    int nrow = row + delRow[j];
                    int ncol = col + delCol[j];

                    if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m){
                        if(!visited[nrow][ncol] && grid[nrow][ncol] == 1){
                            visited[nrow][ncol] = 1;
                            q.push({nrow,ncol});
                        }
                    }
                }

            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        //Obsertvation all 1s that are directly or indirectly connected to boundary 1's can be escaped and the no of 1's left will be ans
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int> (m, 0));

        queue<pair<int,int>> q;

        //startRow and endRow
        for(int j = 0; j < m; j++){
            //startRow
            if(grid[0][j] == 1 && !visited[0][j]){
                q.push({0,j});
                visited[0][j] = 1;                
            }
            if(grid[n-1][j] == 1 && !visited[n-1][j]){
                q.push({n-1,j});
                visited[n-1][j] = 1;
            }
        }
        
        //startCol and endCol
        for(int i = 0; i < n; i++){
            //startCol
            if(grid[i][0] == 1 && !visited[i][0]){
                q.push({i,0});
                visited[i][0] = 1;
            }
            //endCol
            if(grid[i][m-1] == 1 && !visited[i][m-1]){
                q.push({i,m-1});
                visited[i][m-1] = 1;
            }
        }

        bfs(q,visited,grid,n,m);

        int ct = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    ct++;
                }
            }
        }

        return ct;
        

    }
};