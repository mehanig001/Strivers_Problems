class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        vector<int> vis(n*m,0);
        int ct = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    vis[i*m + j] = 1;
                }
                else if(grid[i][j] == 1)ct++;
            }
        }
        

        int delr[] = {-1,0,1,0};
        int delc[] = {0,1,0,-1};

        int time = 0;
        while(!q.empty()){
            int N = q.size();
            for(int it = 0; it < N; it++){
                auto pr = q.front();
                q.pop();
                int r = pr.first;
                int c = pr.second;
                for(int i = 0; i < 4; i++){
                    int nr = r+delr[i];
                    int nc = c+delc[i];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                        if(grid[nr][nc] == 1 && !vis[nr*m+nc]){
                            ct--;
                            vis[nr*m+nc] = 1;
                            q.push({nr,nc});
                        }
                    }
                }
            }
            time++;
        }
        // cout<<ct<<endl;
        if(ct != 0)return -1;
        return max(0,time-1);
    }
};